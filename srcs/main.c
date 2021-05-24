/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:11:32 by atrouill          #+#    #+#             */
/*   Updated: 2021/05/24 14:02:17 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

t_glob	*g_glob;


int			ft_ischarset(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*get_file_name(char *s, int *i)
{
	int 	j;
	char	*filename;

	filename = NULL;
	while (s[*i] == ' ')
		(*i)++;
	j = *i;
	while (s[j] && (ft_isalnum(s[j]) || s[j] == '_' || s[j] == '-' || s[j] == '.'))
		j++;
	if (*i != j)
		filename = ft_substr(s, *i, j - *i);
	return (filename);
}

int			ft_less(t_list *tmp, int *i, int *fdin)
{
	char	*filename;

	filename = NULL;
	while (tmp && !(filename))
	{
		if ((filename = get_file_name(tmp->content, i)))
			break ;
		tmp = tmp->next;
	}
	if (filename)
	{
		*fdin = open(filename, O_RDONLY);
		return (0);
	}
	ft_putstr_fd("Error: filename not specified after rediction\n", 2);
	return (-1);
}

int			ft_reverse()
{
	return (0);
}

int			ft_redirect(t_list *tmp, int *i, int *fdin, int *fdout)
{
	int		r;

	r = 0;
	(void)fdout;
	if ((char)tmp->content[*i] == '<' && tmp->content[*i] == '>' )
		r = ft_reverse();
	else if (tmp->content[*i] == '<')
		r = ft_less(tmp, i, fdin);
	// else
		// r = ft_more();
	return (r);
}

int			ft_redirection_check(t_list *cmds, int *fdin, int *fdout)
{
	t_list	*tmp;
	int		i;

	tmp = cmds;
	while (tmp)
	{
		i = -1;
		while (tmp->content[++i])
		{
			if (ft_ischarset(tmp->content[i], "<>"))
				ft_redirect(tmp, &i, fdin, fdout);
		}
		tmp = tmp->next;
	}
	if (!(*fdout))
		*fdout = dup(g_glob->save_out);
	if (!(*fdin))
		*fdin = dup(g_glob->save_in);
	return (0);
}

int			exec_path(char *s)
{
	if (is_builtin(s))
		return (0);
	
}

int			ft_exec(t_lexer *lexed)
{
	t_list	*cmds;
	t_lexer	*tmp;
	int		fdin;
	int		fdout;
	int		fdtemp;
	int		fdpipe[2];
	int		ret;

	tmp = lexed;
	while (tmp)
	{
		g_glob->save_in = dup(0);
		g_glob->save_out = dup(1);
		cmds = ft_parse(tmp->cmd);
		ft_redirection_check(cmds, &fdin, &fdtemp);
		dup2(fdin, 0);
		close(fdin);		
		if (tmp->next->token == T_SEMICOLON || tmp->next == NULL)
		{	
			if (fdtemp)
				fdout = fdtemp;
			else
				fdout = dup(g_glob->save_out);
		}
		else
		{
			pipe(fdpipe);
			fdout=fdpipe[1];
			fdin=fdpipe[0];
		}
		dup2(fdout,1);
		close(fdout);
		ret=fork();
		if(ret==0)
		{
			execve(cmds->content,  );
			exit(1);
		}
		dup2(g_glob->save_in, 0);
		dup2(g_glob->save_out, 1);
		close(g_glob->save_in);
		close(g_glob->save_out);
		waitpid(ret, NULL, NULL);
		tmp = tmp->next;
	}
	return (0);	
// 	{

   
//      //set the initial input 

//     if (infile)
//        fdin = open(infile,O_READ); 
//     else
//       fdin=dup(tmpin);
  
//     int ret;
//     int fdout;
//     for(i=0;i<numsimplecommands; i++) {
//       //redirect input
//       dup2(fdin, 0);
//       close(fdin);
//       //setup output
//       if (i == numsimplecommands­1){
//         // Last simple command 
//         if(outfile)
//           fdout=open(outfile,â€¦â€¦);
//         else
//           fdout=dup(tmpout);
//       }
  
//        else {
//           // Not last 
//           //simple command
//           //create pipe
//           int fdpipe[2];
//           pipe(fdpipe);
//           fdout=fdpipe[1];
//           fdin=fdpipe[0];
//        }// if/else
  
//        // Redirect output
//        dup2(fdout,1);
//        close(fdout);
   
//        // Create child process
//        ret=fork(); 
//        if(ret==0) {
//          execvp(scmd[i].args[0], scmd[i].args);
//          perror(â€œexecvpâ€);
//          _exit(1);
//        }
//      } //  for
   
//      //restore in/out defaults
//      dup2(tmpin,0);
//      dup2(tmpout,1);
//      close(tmpin);
//      close(tmpout);
  
//      if (!background) {
//        // Wait for last command
//        waitpid(ret, NULL);
//      }
  
//   }
}

/*
** Reads user input and launches parsing and execution
**	@return 0 on success, < 0 if failure
*/
int			ft_reader(void)
{
	t_lexer	*lexed;
	char	*tmp;

	tmp = NULL;
	ft_prompt();
	get_next_line(1, &tmp);
	lexed = lexer(tmp);
	ft_exec(lexed);
	return (0);
}

int			main(void)
{
	int		x;

	x = 0;
	g_glob = NULL;
  	if(ft_init_gobal())
		return (-1);
	ft_env();
	//signal(SIGINT, c_handler);
	//signal(SIGQUIT, d_handler);
	while (!(x))
		x = ft_reader();
	free_glob();
	return (0);
}

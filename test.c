/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:48:16 by atrouill          #+#    #+#             */
/*   Updated: 2021/11/25 13:10:45 by atrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if DEBUG
  #include <stdio.h>
  #define debug(x, ...)      do{fprintf(stderr, "%s:%s(%u): " x "\n", __FILE__, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);}while(0)
#else
  #define debug(x, ...)      /* x */
#endif

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

volatile sig_atomic_t	returning;

static void	int_par_handle(int sig)
{
	debug("Recive SIGINT to parent : [%d]", getpid());
	returning = 130;
}

static void	int_child_handle(int sig)
{
	debug("Recive SIGINT to child : [%d]", getpid());
	exit(130);
}

static void	quit_par_handle(int sig)
{
	debug("Recive SIGQUIT to parent : [%d]", getpid());
	returning = 131;
}

static void	quit_child_handle(int sig)
{
	debug("Recive SIGQUIT to child : [%d]", getpid());
	returning = 131;
	exit(131);
}

void	launch_child(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		ret;

	(void)argc;
	pid = fork();
	if (pid == 0)
	{
		debug("Child start with pid : [%d]", getpid());
		signal(SIGINT, int_child_handle);
		signal(SIGQUIT, quit_child_handle);
		execve("/usr/bin/cat", argv, envp);
		exit(0);
	}
	waitpid(pid, &ret, 0);
	if (WIFEXITED(ret))
		returning = WEXITSTATUS(ret);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;

	debug("Launch with pid : [%d]", getpid());
	signal(SIGINT, int_par_handle);
	signal(SIGQUIT, quit_par_handle);
	launch_child(argc, argv, envp);
	debug("Return code is : [%d]", returning);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:48:16 by atrouill          #+#    #+#             */
/*   Updated: 2021/11/24 18:58:08 by atrouill         ###   ########.fr       */
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

static void	int_par_handle(int sig)
{
	debug("Recive SIGINT to parent : [%d]", getpid());
}

static void	int_child_handle(int sig)
{
	debug("Recive SIGINT to child : [%d]", getpid());
	exit(130);
}

static void	quit_par_handle(int sig)
{
	debug("Recive SIGQUIT to parent : [%d]", getpid());
}

static void	quit_child_handle(int sig)
{
	debug("Recive SIGQUIT to child : [%d]", getpid());
}


int	main(void)
{
	int		ret;
	pid_t	pid;

	debug("Launch with pid : [%d]", getpid());
	signal(SIGINT, int_par_handle);
	signal(SIGQUIT, quit_par_handle);
	pid = fork();
	if (pid == 0)
	{
		debug("Child start with pid : [%d]", getpid());
		signal(SIGINT, int_child_handle);
		signal(SIGQUIT, quit_child_handle);
		sleep(30);
		exit(0);
	}
	waitpid(pid, &ret, 0);
	debug("Return code is : [%d]", ret);
	return (0);
}

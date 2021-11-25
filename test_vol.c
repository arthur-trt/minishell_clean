/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrouill <atrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:11:47 by atrouill          #+#    #+#             */
/*   Updated: 2021/11/25 13:23:33 by atrouill         ###   ########.fr       */
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
# include <stdbool.h>

volatile sig_atomic_t	cont = true;

void	sig_handler(int sig)
{
	(void)sig;
	cont = false;
}

int	main(void)
{
	signal(SIGINT, sig_handler);
	while (cont)
	{
		sleep(2);
	}
	debug("J'ai finis poto");
	return (0);
}

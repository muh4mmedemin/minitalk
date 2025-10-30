/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 02:13:59 by muayna            #+#    #+#             */
/*   Updated: 2025/10/31 02:19:40 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	signal_test(int signum, siginfo_t *info, void *context)
{
	static char	str;

	g_bit++;
	str = str << 1;
	if (SIGUSR1 == signum)
	{
		str = str | 1;
	}
	if (bit == 8)
	{
		write(1, &str, 1);
		str = '\0';
		g_bit = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	s_sigaction;
	int					test;

	test = getpid();
	g_bit = 0;
	sigemptyset(&s_sigaction.sa_mask);
	s_sigaction.sa_sigaction = signal_test;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, NULL);
	sigaction(SIGUSR2, &s_sigaction, NULL);
	printf("Server pid : %d\n", test);
	while (1)
		pause();
	return (0);
}

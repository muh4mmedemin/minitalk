/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 23:15:56 by muayna            #+#    #+#             */
/*   Updated: 2025/10/31 17:06:55 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	g_bit2;

void	send_signal(int binary, int pid_id, int *bit2_temp)
{
	int	check_signal;

	if (binary == 1)
		check_signal = kill(pid_id, SIGUSR1);
	else if (binary == 0)
		check_signal = kill(pid_id, SIGUSR2);
	if (check_signal != 0)
	{
		ft_printf("Signal Error\n");
		exit(1);
	}
	while (g_bit2 == *bit2_temp)
		usleep(100);
}

void	array_all_zero(int binary[])
{
	int	i;

	i = 0;
	while (i < 8)
	{
		binary[i] = 0;
		i++;
	}
}

void	decimal_to_binary(int c, int pid_id)
{
	int	binary[8];
	int	loop;
	int	operation;
	int	temp;
	int	bit2_temp;

	array_all_zero(binary);
	loop = 7;
	temp = c;
	while (loop >= 0 && temp > 0)
	{
		binary[loop] = temp % 2;
		temp = temp / 2;
		loop--;
	}
	loop = 0;
	g_bit2 = 0;
	while (loop < 8)
	{
		bit2_temp = g_bit2;
		send_signal(binary[loop], pid_id, &bit2_temp);
		loop++;
	}
}

void	system_resume(int empty)
{
	g_bit2++;
	(void)empty;
}

int	main(int argc, char *argv[])
{
	unsigned long long	i;
	int					pid_id;

	if (argc != 3)
	{
		ft_printf("Arguments errors\n");
		exit(1);
	}
	i = 0;
	pid_id = ft_atoi(argv[1]);
	signal(SIGUSR1, system_resume);
	while (argv[2][i])
	{
		decimal_to_binary(argv[2][i], pid_id);
		i++;
	}
}

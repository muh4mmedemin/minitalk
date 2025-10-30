/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:54:43 by muayna            #+#    #+#             */
/*   Updated: 2025/10/30 23:02:49 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int bit2;

void send_signal(int binary, int pid_id, int *bit2_temp)
{
    if(binary == 1)
        kill(pid_id, SIGUSR1);
    else if (binary == 0)
        kill(pid_id, SIGUSR2);
    while (bit2 == *bit2_temp)
    {
        usleep(100);
    }
}

void decimal_to_binary(int c, int pid_id)
{
    int binary[8] = {0};
    int loop = 7;
    int operation;
    int temp;
    int bit2_temp;
    
    temp = c;
    while (loop >= 0 && temp > 0)
    {
        binary[loop] = temp % 2;
        temp = temp / 2;
        loop--;
    }
    loop = 0;
    bit2 = 0;
    while (loop < 8)
    {
        bit2_temp = bit2;
        send_signal(binary[loop], pid_id, &bit2_temp);
        loop++;
    }
}


void system_resume(int empty)
{
    bit2++;
    (void)empty;
}

int main (int argc, char *argv[])
{
    unsigned long long i = 0;
    int pid_id = atoi(argv[1]);
    signal(SIGUSR1, system_resume);
    while(argv[2][i])
    {
        decimal_to_binary(argv[2][i], pid_id);
        i++;
    }
}
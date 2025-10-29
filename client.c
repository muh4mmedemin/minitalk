/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:54:43 by muayna            #+#    #+#             */
/*   Updated: 2025/10/29 17:36:39 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>



void send_signal(int binary, int pid_id)
{
    if(binary == 1)
        kill(pid_id, SIGUSR1);
    else if (binary == 0)
        kill(pid_id, SIGUSR2);
    usleep(100);
}

void decimal_to_binary(int c, int pid_id)
{
    int binary[8] = {0};
    int loop = 7;
    int operation;
    int temp;
    temp = c;
    while (loop >= 0 && temp > 0)
    {
        binary[loop] = temp % 2;
        temp = temp / 2;
        loop--;
    }
    loop = 0;
    while (loop < 8)
    {
        send_signal(binary[loop], pid_id);
        loop++;
    }
}

void system_resume(int empty)
{
    
    (void)empty;
}

int main (int argc, char *argv[])
{
    int i = 0;
    int pid_id = atoi(argv[1]);
    signal(SIGUSR1, system_resume);
    while(argv[2][i])
    {
        decimal_to_binary(argv[2][i], pid_id);
        i++;
    }
}
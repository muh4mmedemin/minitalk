/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:54:43 by muayna            #+#    #+#             */
/*   Updated: 2025/10/29 14:47:54 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

char decimal_to_binary(int c)
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
        printf("%d\n", binary[loop]);
        loop++;
    }
}

int main (int argc, char *argv[])
{
    //int pid_id = atoi(argv[1]);
    int i = 0;
    char temp;
    while(argv[2][i])
    {
        temp = decimal_to_binary(argv[2][i]);
        i++;
    }
    //kill(pid_id, SIGUSR1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:49:45 by muayna            #+#    #+#             */
/*   Updated: 2025/10/29 14:12:47 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void signal_test(int signum)
{
    char str;
    int bit;

    str = 0;
    bit = 1;
    while(bit < 193)
    {
        if (SIGUSR1 == signum)
        {
            str = str & bit;
        }
        bit = bit << 1;
    }
    printf("%c\n", str);
}

int main ()
{
    int test = getpid();
    printf("Server pid : %d\n", test);
    signal(SIGUSR1, signal_test);
    while (1)
        pause();
    return 0;
}
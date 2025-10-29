    /* ************************************************************************** */
    /*                                                                            */
    /*                                                        :::      ::::::::   */
    /*   server.c                                           :+:      :+:    :+:   */
    /*                                                    +:+ +:+         +:+     */
    /*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
    /*                                                +#+#+#+#+#+   +#+           */
    /*   Created: 2025/10/29 13:49:45 by muayna            #+#    #+#             */
    /*   Updated: 2025/10/29 16:09:27 by muayna           ###   ########.fr       */
    /*                                                                            */
    /* ************************************************************************** */

    #define _XOPEN_SOURCE 700

    #include <signal.h>
    #include <sys/types.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int bit = 0;

    void signal_test(int signum, siginfo_t *info, void *context)
    {
        static char str;
        bit++;
        str = str << 1;
        if (SIGUSR1 == signum)
        {            
            str = str | 1;
        }
        if(bit == 8)
        {
            write(1, &str, 1);
            kill(info->si_pid, SIGUSR1);
            bit = 0;
            str = '\0';
        }
    }

    int main ()
    {
        int test = getpid();
        struct sigaction s_sigaction;

        s_sigaction.sa_sigaction = signal_test;
        s_sigaction.sa_flags = SA_SIGINFO;
        sigemptyset(&s_sigaction.sa_mask);
        printf("Server pid : %d\n", test);
        sigaction(SIGUSR1, &s_sigaction, NULL);
        sigaction(SIGUSR2, &s_sigaction, NULL);
        while (1)
            pause();
        return 0;
    }
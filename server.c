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

    #include "server.h"

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
            str = '\0';
            bit = 0;
        }
        kill(info->si_pid, SIGUSR1);
    }

    int main ()
    {
        int test = getpid();
        struct sigaction s_sigaction;
        bit = 0;
        sigemptyset(&s_sigaction.sa_mask);
        s_sigaction.sa_sigaction = signal_test;
        s_sigaction.sa_flags = SA_SIGINFO;
        sigaction(SIGUSR1, &s_sigaction, NULL);
        sigaction(SIGUSR2, &s_sigaction, NULL);
        printf("Server pid : %d\n", test);
        while (1)
            pause();
        return 0;
    }

/*---
Question 1c
: Write a separate program (for each time domain) to set a interval itimer_real in 10s and 10ms - `ITIMER_PROC`
NAME---------Chandransh singh chouhan
ROLLNUMBER---MT2024033
*/
#include <sys/time.h> // Import `setitimer`
#include <signal.h>   // Import for `signal`
#include <unistd.h>   // Import for `pause`
#include <stdio.h>    // Import `perror` & `printf`

void main(int argc, char *argv[])
{
    int timerstate; // Determines success of `setitimer` call

    struct itimerval itimer_prof;

    if (argc != 2)
    {
        printf("Pass 1 for 10s itimer_prof or 2 for 10ms itimer_prof\n");
        _exit(0);
    }
int choice = atoi(argv[1]);

    if (choice  == 1)//
    {
        // Setting a interval itimer_prof for 10s
        itimer_prof.it_interval.tv_sec = 0;
        itimer_prof.it_interval.tv_usec = 0;
        itimer_prof.it_value.tv_sec = 10;
        itimer_prof.it_value.tv_usec = 0;
    }
    else if (choice== 2)
    {
        // Setting a interval itimer_prof for 10ms
        itimer_prof.it_interval.tv_sec = 0;
        itimer_prof.it_interval.tv_usec = 0;
        itimer_prof.it_value.tv_sec = 0;
        itimer_prof.it_value.tv_usec = 10000;
    }

    timerstate = setitimer(ITIMER_PROF, &itimer_prof, 0);
    if (timerstate == -1)
        perror("Error while setting an interval itimer_prof!");

    while(1);
}
/*
Profiling timer expired
*/

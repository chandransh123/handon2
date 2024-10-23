
/*---
Question 1b
: Write a separate program (for each time domain) to set a interval itimer_real in 10s and 10ms - `ITIMER_VIRTUAL`
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

    struct itimerval itimer_virtual;

    if (argc != 2)
    {
        printf("Pass 1 for 10s itimer_virtual or 2 for 10ms itimer_virtual\n");
        _exit(0);
    }
   int choice = atoi(argv[1]);
    if (choice == 1)
    {
        // Setting a interval itimer_virtual for 10s
        itimer_virtual.it_interval.tv_sec = 0;
        itimer_virtual.it_interval.tv_usec = 0;
        itimer_virtual.it_value.tv_sec = 10;
        itimer_virtual.it_value.tv_usec = 0;
    }
    else if (choice == 2)
    {
        // Setting a interval itimer_virtual for 10ms
        itimer_virtual.it_interval.tv_sec = 0;
        itimer_virtual.it_interval.tv_usec = 0;
        itimer_virtual.it_value.tv_sec = 0;
        itimer_virtual.it_value.tv_usec = 10000;
    }

    timerstate = setitimer(ITIMER_VIRTUAL, &itimer_virtual, 0);
    if (timerstate == -1)
        perror("Error while setting an interval itimer_virtual!");

    while(1);
}
/*Virtual timer expired
*/
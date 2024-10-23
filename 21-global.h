#include <errno.h>

char *fifoOneName = "./21-fifoOne";
char *fifoTwoName = "./21-fifoTwo";

void init()
{
    int fifoOneState,fifoTwoState; // Determines the success of the `mkfifo` call

    fifoOneState = mkfifo(fifoOneName, S_IRWXU);
    if (!(errno == EEXIST || fifoOneState != -1))
        perror("Error while creating FIFO file fifoOne");

   fifoTwoState = mkfifo(fifoTwoName, S_IRWXU);
    if (!(errno == EEXIST ||fifoTwoState != -1))
        perror("Error while creating FIFO file fifoTwo");
}
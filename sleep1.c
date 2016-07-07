#include <unistd.h>
#include <signal.h>
#include <stdio.h>


int main()
{
    void  wakeup(int);

    printf("abou to sleep for 4 second\n");
    signal(SIGALRM, wakeup);
    alarm(4);
    pause();
    printf("Moring so soon?\n");
    return 0;
}

void wakeup(int signum){

}

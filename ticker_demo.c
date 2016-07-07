#include <unistd.h>
#include <sys/time.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    void countdown(int);
    int set_ticker(int);
    signal(SIGALRM, countdown);
    if (set_ticker(500) == -1)
        perror("set_ticker error");
    else
        while(1)
            pause();
    return 0;
}

void countdown(int signum){
    static int num = 10;
    printf("%d..", num--);
    fflush(NULL);
    if (num < 0){
        printf("Done!\n");
        exit(0);
    }
}


int set_ticker(int n_msecs){
    struct itimerval new_timeset;
    long n_sec, n_usecs;
    n_sec = n_msecs / 1000; // n_sec == 0
    n_usecs = (n_msecs % 1000) * 1000L; // n_usecs == 500000 
    //printf("n_sec = %d -- n_usecs = %d", n_sec, n_usecs);

    new_timeset.it_interval.tv_sec = n_sec;
    new_timeset.it_interval.tv_usec = n_usecs;

    new_timeset.it_value.tv_sec = n_sec;
    new_timeset.it_value.tv_usec  = n_usecs;

    return setitimer(ITIMER_REAL, &new_timeset, NULL);

}
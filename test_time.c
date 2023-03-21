#include <stdio.h>
#include <sys/time.h>

int main(void)
{
    struct timeval current_time;
    
    gettimeofday(&current_time, NULL);
    printf("seconds : %ld\nmicro seconds : %lu\n", current_time.tv_sec, current_time.tv_usec);
    return 0;
}
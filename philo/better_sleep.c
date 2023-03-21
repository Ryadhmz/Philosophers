#include "philosophers.h"

long long int ft_actual_time(void)
{
    struct timeval current_time;
    long long int actual_time_mili;

    gettimeofday(&current_time, NULL);
    actual_time_mili = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
    return(actual_time_mili);
}

void better_sleep(unsigned int time_to_eat)
{
    long long int actual_time;
    long long int end_time;

    actual_time = ft_actual_time();
    end_time = ft_actual_time + time_to_eat;

    while(ft_actual_time() < end_time);
}
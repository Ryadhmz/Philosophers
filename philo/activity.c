#include "philosophers.h"

void print_activity(int fd, char *str)
{
    printf("%lld %u %s\n", ft_actual_time(), fd, str);
}

void activity(t_phil *ph)
{
    pthread_mutex_lock(&(ph->f_r));
    pthread_mutex_lock(&(ph->mutex_write)); // donner a tout les threads le MEME mutex write
    print_activity(ph->id, "has taken a fork");
    pthread_mutex_destroy()
}
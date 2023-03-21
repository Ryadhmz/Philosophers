#include "philosophers.h"

void thread

int thread_phil(t_all *all)
{
    int i;

    i = 0;

    while(i < all->arg.nb_phil)
    {
        all->phil[i].arg = &all->arg;
        if(pthread_create(&all->phil[i].phil_thread, NULL, &thread, NULL) != 0)
        {
            printf("Error when creating the thread\n");
            return(-1);
        }
        i++;
    }
    return 0;
}
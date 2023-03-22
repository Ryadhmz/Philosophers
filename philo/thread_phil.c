/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_phil.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:37:50 by rhamza            #+#    #+#             */
/*   Updated: 2023/03/22 14:37:50 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *thread(void *phil_void)
{
    t_phil *ph;

    ph = (t_phil *)phil_void;
    if(ph->id % 2 == 0)
        better_sleep(phil_void->arg.time_to_eat / 10);
    activity(ph);
}

int thread_phil(t_all *all)
{
    int i;

    i = 0;
    while(i < all->arg.nb_phil)
    {
        all->phil[i].arg = &all->arg;
        if(pthread_create(&all->phil[i].phil_thread, NULL, &thread, (void*)&all->phil[i]) != 0)
        {
            printf("Error when creating the thread\n");
            return(-1);
        }
        i++;
    }
    return 0;
}
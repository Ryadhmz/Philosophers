/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_phil.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:37:50 by rhamza            #+#    #+#             */
/*   Updated: 2023/03/30 16:31:48 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *thread_must_eat(void *all_void)
{
    unsigned int eat;
    t_all *all;

    eat = 0;
    all = (t_all *)all_void;
    while(eat < all->arg.each_phil_m_eat)
    {
        better_sleep(all->arg.time_to_eat);
        eat += 1;
    }    
    if(eat == all->arg.each_phil_m_eat)
        all->arg.finish = 1;
    return (NULL);
}

void *thread_dead(void *phil_void)
{
    t_phil *ph;
    ph = (t_phil *)phil_void;
    better_sleep(ph->arg->time_to_die);
    if_died(ph);
    return (NULL);
}

void *thread(void *phil_void)
{
    t_phil *ph;
    
    ph = (t_phil *)phil_void;
    while(1)
    {
        if(ph->arg->finish == 1) // faire un truc pour savoir si chaque philo a bien mange 
            break;
        if(ph->id % 2 == 0)
            better_sleep(ph->arg->time_to_eat / 10);
        ph->begin_activity = ft_actual_time();
        if(pthread_create(&ph->phil_dead, NULL, &thread_dead, (void*)ph) != 0)
        {
            printf("Error when creating the thread\n");
            return (NULL);
        }
        pthread_detach(ph->phil_dead);
        if(activity(ph) == -1)
            return(NULL);
    }
    return (NULL);
}

int thread_phil(t_all *all)
{
    unsigned int i;

    i = 0;
        
    while(i < all->arg.nb_phil)
    {
        all->phil[i].arg = &all->arg;
        if(pthread_create(&all->phil[i].phil_thread, NULL, &thread, (void*)&all->phil[i]) != 0)
        {
            printf("Error when creating the thread\n");
            return(-1);
        }
        pthread_detach(all->phil[i].phil_thread);
        if(pthread_create(&all->thread_all, NULL, &thread_must_eat, (void*)&all) != 0)
        {
            printf("Error when creating the thread\n");
            return(-1);
        }
        pthread_detach(all->thread_all);
        i++;
    }
    while(all->arg.finish != 1);
    // ft_finish(); // la fonction finish va tout free comme il faut pour sortir proprement
    return 0;
}
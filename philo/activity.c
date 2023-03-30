/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:37:44 by rhamza            #+#    #+#             */
/*   Updated: 2023/03/30 02:27:03 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void print_activity(int fd, char *str)
{
    printf("%lld %u %s\n", ft_actual_time(), fd, str);
}

int solo_philo(t_phil *ph)
{
    better_sleep(ph->arg->time_to_eat);
    pthread_mutex_unlock(&(ph->f_r));
    if(if_died(ph) == -1)
        return (-1);
    if(ph->nb_eat >= ph->arg->each_phil_m_eat)
    {
        ph->arg->finish = 1;
        return(-1);
    }
    return (0);
}

int activity(t_phil *ph)
{
    ph->begin_activity = ft_actual_time(); 
    pthread_mutex_lock(&(ph->f_r));
    pthread_mutex_lock((ph->ptr_mutex_write)); // donner a tout les threads le MEME mutex write
    print_activity(ph->id, "has taken a fork");
    pthread_mutex_unlock((ph->ptr_mutex_write));
    if(ph->arg->nb_phil == 1)
        return(solo_philo(ph));
    pthread_mutex_lock((ph->f_l));
    pthread_mutex_lock((ph->ptr_mutex_write));
    print_activity(ph->id, "has taken a fork");
    pthread_mutex_unlock((ph->ptr_mutex_write));
    pthread_mutex_lock((ph->ptr_mutex_write));
    print_activity(ph->id, "is eating");
    pthread_mutex_unlock((ph->ptr_mutex_write));
    better_sleep(ph->arg->time_to_eat);
    pthread_mutex_unlock(&(ph->f_r));
    pthread_mutex_unlock((ph->f_l));
    // if(if_died(ph) == -1)
    //     return (-1);
    pthread_mutex_lock((ph->ptr_mutex_write));
    print_activity(ph->id, "is sleeping");
    pthread_mutex_unlock((ph->ptr_mutex_write));
    if(if_died(ph) == -1)
        return (-1);
    better_sleep(ph->arg->time_to_sleep);
    pthread_mutex_lock((ph->ptr_mutex_write));
    print_activity(ph->id, "is thinking");
    pthread_mutex_unlock((ph->ptr_mutex_write));
    // if(if_died(ph) == -1)
    //     return (-1);
    if(ph->nb_eat >= ph->arg->each_phil_m_eat)
        return(-1);
    return (0);
}
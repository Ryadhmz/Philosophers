/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   died_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:37:22 by rhamza            #+#    #+#             */
/*   Updated: 2023/03/29 23:41:00 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int if_died(t_phil *phil)
{
    printf("Entre if died\n");
    printf("Actual time : %lld, Begin activity : %lld, Time to die : %u\n", ft_actual_time(), phil->begin_activity, phil->arg->time_to_die);
    if((ft_actual_time() - phil->begin_activity) >= phil->arg->time_to_die)
    {
        pthread_mutex_lock((phil->ptr_mutex_write));
        print_activity(phil->id, "died");
        pthread_mutex_destroy((phil->ptr_mutex_write));
        phil->arg->finish = 1;
        return (-1);
    }
    return (0);
}

// void if_end(t_phil *phil)
// {
//     if(phil->nb_eat >= phil->arg->each_phil_m_eat)
//     {
        
//     }
// }
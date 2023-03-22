/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   died_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:37:22 by rhamza            #+#    #+#             */
/*   Updated: 2023/03/22 15:13:03 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int if_died(t_phil *phil)
{
    if(ft_actual_time() - phil.begin_activity > phil->arg.time_to_eat)
    {
        pthread_mutex_lock(&(ph.ptr_mutex_write));
        print_activity(ph.id, "died");
        phil->arg.finish = 1;
    }
    return (0);
}
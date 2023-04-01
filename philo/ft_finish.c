/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:30:20 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/01 18:26:29 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void ft_finish(t_all *all) // la fonction free tout proprement pour finir le programme comme il se doit
{
    int i;

    i = 0;
    pthread_mutex_destroy(&all->arg.mutex_write);
    while(i < all->arg.nb_phil)
    {
        pthread_mutex_destroy(&all->phil->f_r);
        i++;  
    }
    free(all->phil);
}
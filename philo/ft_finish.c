/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:30:20 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/02 03:51:43 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_finish(t_all *all)
{
	unsigned int	i;

	i = 0;
	pthread_mutex_destroy(&all->arg.mutex_write);
	while (i < all->arg.nb_phil)
	{
		pthread_mutex_destroy(&all->phil->f_r);
		i++;
	}
	free(all->phil);
	free(all);
	all = NULL;
}

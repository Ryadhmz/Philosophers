/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryad <ryad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 06:45:53 by rhamza            #+#    #+#             */
/*   Updated: 2023/03/18 15:30:01 by ryad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void init_struct_philo(t_all *all)
{
        
}

void init_struct_arg(char **argv, int argc, t_all *all)
{
    all->arg.nb_phil = ft_atoi(argv[1]);
    all->arg.time_to_die = ft_atoi(argv[2]);
    all->arg.time_to_eat = ft_atoi(argv[3]);
    all->arg.time_to_sleep = ft_atoi(argv[4]);
    if(argc == 6)
        all->arg.each_phil_m_eat = ft_atoi(argv[5]); 
}

int main(int argc, char **argv)
{
    t_all *all;

    if(check_arg(argc, argv) == -1)
    {
        printf("Bad input\n");
        return(-1);
    }
    init_struct_arg(argv, argc, all);
    init_struct_philo(all);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryad <ryad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 06:45:53 by rhamza            #+#    #+#             */
/*   Updated: 2023/03/21 15:07:14 by ryad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int init_struct_philo(t_all *all)
{
    int i;

    i = 0;
    all->phil = malloc(sizeof(t_phil) * all->arg.nb_phil);
    if(!(all->phil))
        return(-1);
    while(i < all->arg.nb_phil)
    {
        all->phil[i].id = i + 1;
        all->phil[i].nb_eat = 0;
        all->phil[i].f_l = NULL;
        if(pthread_mutex_init(&all->phil[i].f_r, NULL) != 0)
        {
            printf("Error init mutex\n");
            return (-1);
        }
        if(i == (all->arg.nb_phil - 1))
            all->phil[0].f_l = &all->phil[i].f_r;
        else if(i != 0 && i != all->arg.nb_phil - 1)
            all->phil[i].f_l = &all->phil[i-1].f_r;
        i++;
    }
    return (0);
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
    if(init_struct_philo(all) == -1)
        return(-1);
    if(thread_phil(all) == -1)
        return(-1);
}
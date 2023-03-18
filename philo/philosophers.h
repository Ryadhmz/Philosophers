/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryad <ryad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 06:45:48 by rhamza            #+#    #+#             */
/*   Updated: 2023/03/18 15:28:37 by ryad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct arg_struct
{
    unsigned int nb_phil;
    unsigned int time_to_die;
    unsigned int time_to_eat;
    unsigned int time_to_sleep;
    unsigned int each_phil_m_eat;
}   t_arg;

typedef struct philo_struct
{
    unsigned int id;
    unsigned int nb_eat;
    pthread_mutex_t f_r;
    pthread_mutex_t *f_l;
    t_arg *arg;
    pthread_t phil_thread;
    
}   t_phil;

typedef struct all_struct
{
    t_arg arg;
    t_phil *phil;
}   t_all;

int ft_strlen(const char *str);
int is_digit(char c);
int check_arg(int argc, char **argv);
int	ft_atoi(const char *str);

#endif
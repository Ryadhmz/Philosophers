/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 06:45:48 by rhamza            #+#    #+#             */
/*   Updated: 2023/03/29 14:27:19 by rhamza           ###   ########.fr       */
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
    int finish;
    pthread_mutex_t mutex_write;
    
}   t_arg;

typedef struct philo_struct
{
    unsigned int id;
    unsigned int nb_eat;
    unsigned int begin_activity;
    pthread_mutex_t f_r; // fourchette droite
    pthread_mutex_t *f_l; // fourchette gauche
    pthread_mutex_t *ptr_mutex_write;
    pthread_t phil_thread;
    t_arg *arg;
    
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
int thread_phil(t_all *all);
void better_sleep(unsigned int time_to_eat);
long long int ft_actual_time(void);
int activity(t_phil *ph);
void print_activity(int fd, char *str);
int if_died(t_phil *phil);

#endif
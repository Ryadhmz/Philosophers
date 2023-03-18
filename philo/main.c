/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryad <ryad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 06:45:53 by rhamza            #+#    #+#             */
/*   Updated: 2023/03/18 15:21:14 by ryad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int is_possible_input(char *str)
{
    int i;
    int nb;

    i = 0;
    nb = 0;
    if(ft_strlen(str) > 10)
        return(-1);
    while(str[i])
    {
        if(is_nb(str[i]) == -1)
            return(-1);
        i++;
    }
    nb = ft_atoi(str);
    if(nb > 2147483647)
        return(-1);
    return (0);
}

int check_arg(int argc, char **argv)
{
    if(argc < 5 || argc > 6)
        return(-1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

void init_struct(char **argv, int argc, t_all *all)
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
    init_struct(argv, argc, all);
    
}
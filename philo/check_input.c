/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamza <rhamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:37:31 by rhamza            #+#    #+#             */
/*   Updated: 2023/04/01 17:12:08 by rhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int is_digit(char c)
{
    if(c >= '0' && c <= '9')
        return(0);
    else
        return(-1);
}

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
        if(is_digit(str[i]) == -1)
            return(-1);
        i++;
    }
    nb = ft_atoi(str);
    if(nb > 2147483647 || nb <= 0)
        return(-1);
    return (0);
}

int check_arg(int argc, char **argv)
{
    int i;
    
    i = 1;
    if(argc != 5 && argc != 6)
        return(-1);
    while(argv[i])
    {
        if(is_possible_input(argv[i]) == -1)
            return(-1);
        i++;
    }
    return (0);
}
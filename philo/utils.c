#include "philosophers.h"

int is_nb(char c)
{
    if(c >= '0' && c <= '9')
        return(0);
    else
        return(-1);
}

int ft_strlen(const char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;

    return(i);
}
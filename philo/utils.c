#include "philosophers.h"

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

int ft_strlen(const char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;

    return(i);
}


#include "utils.h"

long	ft_strlen(char *str)
{
	long	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
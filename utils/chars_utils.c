

#include "utils.h"

long	ft_strlen(char *str)
{
	long	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_strcmp(char *str1, char *str2)
{
	int		i;

	i = 0;
	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
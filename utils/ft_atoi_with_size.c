

#include "utils.h"

long	ft_atoi_with_size(char *str, long len)
{
	long	res;
	long	i;
	char	neg;

	neg = 0;
	res = 0;
	i = 0;
	if (str[0] == '-')
	{
		neg = 1;
		i++;
	}
	while (i < len)
	{
		res *= 10;
		res += neg ? -(str[i] - '0') : (str[i] - '0');
		i++;
	}
	return (res);
}
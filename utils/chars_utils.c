

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
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *str)
{
	int 	i;
	char	*res;

	if (!(res = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
	{
		ft_putstr("Could not allocate memory\n");
		exit(1);
	}
	res[ft_strlen(str)] = '\0';
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	return (res);
}
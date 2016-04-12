

#include "utils.h"

static int	count_to_split(char *string, long string_len, int to_split)
{
	int		count;
	long	i;
	char	consider;

	count = 0;
	consider = 0;
	i = 0;
	while (i < string_len)
	{
		if (string[i] == to_split)
		{
			if (consider)
			{
				count++;
				consider = 0;
			}
		}
		else if (!consider)
			consider = 1;
		i++;
	}
	if (string[i - 1] != to_split)
		count++;
	return (count);
}

char	**split_on_char(char *string, long string_len, char to_split)
{
	char	**res;
	int		count;
	int		i;
	int		x;
	int		tmp_len;

	count = count_to_split(string, string_len, to_split);
	if (!(res = (char**)malloc(sizeof(char*) * (count + 1))))
	{
		ft_putstr("Could not allocate memory\n");
		exit(1);
	}
	res[count] = NULL;
	x = 0;
	while (string[x] == to_split)
		x++;
	i = 0;
	while (i < count)
	{
		while (string[x] == to_split)
			x++;
		tmp_len = 0;
		while (string[x] != to_split && x < string_len)
		{
			tmp_len++;
			x++;
		}
		if (!(res[i] = (char*)malloc(sizeof(char) * (tmp_len + 1))))
		{
			ft_putstr("Could not allocate memory\n");
			exit(1);
		}
		res[i][tmp_len] = '\0';
		x -= tmp_len;
		tmp_len = 0;
		while (string[x] != to_split && x < string_len)
		{
			res[i][tmp_len] = string[x];
			x++;
			tmp_len++;
		}
		i++;
	}
	return (res);
}
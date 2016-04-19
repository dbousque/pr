

#include "utils.h"

void	ft_putstr(char *str)
{
	int		lol;

	lol = write(1, str, ft_strlen(str));
	(void)lol;
}
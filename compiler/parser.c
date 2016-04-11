

#include "parser.h"

void	parse(char *file_content, long file_len)
{
	char	**lines;
	int		i;

	lines = split_on_char(file_content, file_len, '\n');
	i = 0;
	while (lines[i])
	{
		ft_putstr(lines[i]);
		write(1, "\n\n", 2);
		i++;
	}
}


#include "compiler.h"

void	print_details(void)
{
	ft_putstr("Please specify an input file.\n");
}

void	compile_file(char *filename)
{
	char	*file_content;
	long	file_len;

	file_content = read_file_fast(filename, &file_len);
	parse(file_content, file_len);
	(void)file_content;
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		print_details();
	else
	{
		compile_file(argv[1]);
	}
	return (0);
}
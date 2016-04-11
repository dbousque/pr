

#include "read_source.h"

char	*read_file_fast(char *filename, long *file_size)
{
	char	*file_content;
	int		fd;
	long	size;
	long	ret;
	char	buf[READING_BUF_SIZE];

	size = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		file_opening_error();
		return (NULL);
	}
	while ((ret = read(fd, buf, READING_BUF_SIZE)) > 0)
		size += ret;
	if (ret < 0)
	{
		file_reading_error();
		return (NULL);
	}
	close(fd);

	if (!(file_content = (char*)malloc(sizeof(char) * size)))
		malloc_error();
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		file_opening_error();
		return (NULL);
	}
	if ((read(fd, file_content, size)) < 0)
	{
		file_reading_error();
		return (NULL);
	}
	close(fd);
	*file_size = size;
	return (file_content);
}
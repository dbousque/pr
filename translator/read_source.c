

#include "read_source.h"

t_string	*read_file_fast(char *filename)
{
	t_string	*file_content;
	int			fd;
	long		size;
	long		ret;
	char		buf[READING_BUF_SIZE];

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
	file_content = new_string_of_size(size);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		file_opening_error();
		return (NULL);
	}
	if ((read(fd, file_content->chars, size)) < 0)
	{
		file_reading_error();
		return (NULL);
	}
	set_string_chars(file_content, file_content->chars, size);
	return (file_content);
}
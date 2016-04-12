

#ifndef PARSER_H
# define PARSER_H

# include "compiler.h"

// special treatment for point because of 4.3 vs. myClass.method()
# define POINT_CHAR			'.'
# define SPLIT_N_IGNORE		" \t"
# define SPLIT_N_KEEP		",:=()[]{}"

t_linked_list	*parse(char *file_content, long file_len);
void			print_splitted_lines(t_linked_list *lines);

#endif
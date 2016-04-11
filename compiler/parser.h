

#ifndef PARSER_H
# define PARSER_H

# include "compiler.h"

# define SPLIT_N_IGNORE		" \r\f"
# define SPLIT_N_KEEP		",:\t=()[]{}"

void	parse(char *file_content, long file_len);

#endif
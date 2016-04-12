

#ifndef ABSTRACTION_LAYER_H
# define ABSTRACTION_LAYER_H

# include "compiler.h"

# define STR_FUNCTION_DECL		"def"
# define STR_EQUAL				"="
# define STR_COLON				":"
# define STR_COMMA				","
# define STR_OPEN_PAR			"("
# define STR_CLOSE_PAR			")"
# define STR_OPEN_BRACKET		"["
# define STR_CLOSE_BRACKET		"]"
# define STR_OPEN_CURL_BRAC		"{"
# define STR_CLOSE_CURL_BRAC	"}"
# define STR_POINT				"."
# define STR_SPACE				" "
# define STR_TAB				"\t"

# define FUNCTION_DECL			1
# define EQUAL					2
# define COLON					3
# define COMMA					4
# define OPEN_PAR				5
# define CLOSE_PAR				6
# define OPEN_BRACKET			7
# define CLOSE_BRACKET			8
# define OPEN_CURL_BRAC			9
# define CLOSE_CURL_BRAC		10
# define POINT					11
# define SPACE					12
# define TAB					13
# define NAME					14

t_linked_list	*make_abstraction_layer(t_linked_list *splitted_lines);

#endif
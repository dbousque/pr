

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
# define STR_OPERATION			"+-*/"

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
# define OPERATION				15

# define FUNCTION_NAME			16
# define KEYWORD				17
# define INDENT					18
# define STRING_DEF				19
# define CHARACTER_DEF			20
# define INTEGER_DEF			21
# define FLOAT_DEF				22
# define EQUALITY_CHECK			23
# define COPY_EQUAL				24
# define DEEPCOPY_EQUAL			25
# define COPY					26
# define DEEPCOPY				27
# define VAR_NAME				28

t_linked_list	*make_abstraction_layer(t_linked_list *splitted_lines);

#endif
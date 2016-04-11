

#ifndef PATTERNS_H
# define PATTERNS_H

#define IGNORE					" \r\t"

#define STR_EQUALS				"="
#define STR_EQUALITY_CHECK		"=="
#define STR_CPY_CHAR			":"
#define STR_OPERATION_SYMBOLS	"+-/*"
#define STR_SEPARATOR_SYMBOLS	"({)},"
#define STR_STRING_DELIMIT		"\"'"
#define STR_NUMBER				"0123456789"
#define STR_FUNCTION_DECL		"def"
#define STR_VALUE_START			"0123456789\"'"
#define NB_KEYWORDS				3
#define NB_BUILTIN_FUNCTIONS	1
char	*STR_KEYWORDS[NB_KEYWORDS];
char	*STR_BUILTIN_FUNCTIONS[NB_BUILTIN_FUNCTIONS];


#define UNKNOWN					1
#define VARIABLE				2
#define BUILTIN_FUNCTION		3
#define USER_FUNCTION			4
#define KEYWORD					5
#define EQUALS					6
#define EQUALITY_CHECK			7
#define CPY_CHAR				8
#define OPERATION_SYMBOL		9
#define SEPARATOR_SYMBOL		10
#define STRING_DELIMIT			11
#define FUNCTION_DECL			12
#define VALUE					13


char	NEW_INSTANTIATION[2];
char	REINSTANTIATION[2];
char	PRINT[2];
char	PRINT2[2];
char	FUNCTION[3];
char	FUNCTION2[3];
char	NEW_VALUE[1];

#endif
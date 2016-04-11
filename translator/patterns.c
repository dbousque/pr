

#include "patterns.h"

char	*STR_KEYWORDS[]	=				{
											"for",
											"while",
											"in"
										};

char	*STR_BUILTIN_FUNCTIONS[]	=	{
											"print"
										};


char	NEW_INSTANTIATION[]	=	{UNKNOWN, EQUALS};
char	REINSTANTIATION[]	=	{VARIABLE, EQUALS};
char	PRINT[]				=	{BUILTIN_FUNCTION, VARIABLE};
char	PRINT2[]			=	{BUILTIN_FUNCTION, VALUE};
//char	FUNCTION[]			=	{BUILTIN_FUNCTION, SEPARATOR_SYMBOL, VARIABLE};
//char	FUNCTION2[]			=	{BUILTIN_FUNCTION, SEPARATOR_SYMBOL, VALUE};
//char	FUNCTION3[]			=	{USER_FUNCTION, SEPARATOR_SYMBOL, VARIABLE};
//char	FUNCTION4[]			=	{USER_FUNCTION, SEPARATOR_SYMBOL, VALUE};
char	NEW_VALUE[]			=	{VALUE};

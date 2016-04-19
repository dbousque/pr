%{
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "../../utils/utils.h"
#include "y.tab.h"
%}

%option noyywrap

%%

"return"				{return (RET);}
[a-z_]+					{yylval.tmp_str = ft_strdup(yytext); return (STR);}
[0-9]+					{yylval.tmp_str = ft_strdup(yytext); return (INT);}
[\[\]\+\-\*\/(),=]		{return (yytext[0]);}
[ \t\r\v\f]				{ ; }
.						{return(0);}

%%

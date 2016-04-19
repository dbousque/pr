%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../linked_list.h"
#include "tree.h"
#include "../../utils/utils.h"

t_node			*top_node;

extern int yylex();
%}

%union
{
	char *tmp_str;
	t_node *node;
}

%token '['
%token ']'
%token INT
%token STR
%token RET
%type <node> EXPR STRING INTEGER TOPEXPR ARGUMENT FUNCTION ASSIGN RETURN
%left '+' '-'
%left '*' '/' '='

%start S

%%

S		: TOPEXPR							{top_node = $1;}
		| ASSIGN							{top_node = $1;}
		| RETURN							{top_node = $1;}
		;

RETURN	: RET TOPEXPR						{$$ = new_node(RETU, $2, $2, "");}
		;

ASSIGN	: STRING '=' TOPEXPR				{$$ = new_node(ASSIGNEMENT, $1, $3, "");}
		;

TOPEXPR : EXPR
		| TOPEXPR '*' TOPEXPR				{$$ = new_node(MULTIPL, $1, $3, "");}
		| TOPEXPR '/' TOPEXPR				{$$ = new_node(DIVID, $1, $3, "");}
		| TOPEXPR '+' TOPEXPR				{$$ = new_node(ADD, $1, $3, "");}
		| TOPEXPR '-' TOPEXPR				{$$ = new_node(MINUS, $1, $3, "");}
		;

EXPR	: EXPR '[' TOPEXPR ']'				{$$ = new_node(INDEX, $1, $3, "");}
		| FUNCTION
		| STRING
		| INTEGER
		;

ARGUMENT: TOPEXPR
		| TOPEXPR ',' ARGUMENT				{$$ = new_node(ARGUMENTS, $1, $3, "");}
		;

FUNCTION: STRING '(' ARGUMENT ')'			{$$ = new_node(FUNCTION_NODE, $1, $3, "");}
		; 

STRING	: STR								{$$ = new_node(END_NODE, NULL, NULL, yylval.tmp_str);}
		;

INTEGER	: INT								{$$ = new_node(END_NODE_INT, NULL, NULL, yylval.tmp_str);}
		;

%%

int yyerror(char *msg)
{
	printf("%s\n", msg);
	exit(1);
	return (0);
}

void	print_res_tree(t_node *node)
{
	if (node->action == END_NODE)
	{
		printf("%s", node->repr);
		return ;
	}
	else if (node->action == END_NODE_INT)
	{
		printf("_new_int(%s)", node->repr);
		return ;
	}
	else if (node->action == INDEX)
		printf("_index(");
	else if (node->action == ADD)
		printf("_add(");
	else if (node->action == MINUS)
		printf("_minus(");
	else if (node->action == MULTIPL)
		printf("_multiply(");
	else if (node->action == DIVID)
		printf("_divide(");
	else if (node->action == FUNCTION_NODE)
	{
		print_res_tree(node->left);
		printf("(");
		print_res_tree(node->right);
		printf(")");
		return ;
	}
	else if (node->action == ARGUMENTS)
	{
		print_res_tree(node->left);
		printf(", ");
		print_res_tree(node->right);
		return ;
	}
	else if (node->action == ASSIGNEMENT)
	{
		print_res_tree(node->left);
		printf(" = ");
		print_res_tree(node->right);
		return ;
	}
	else if (node->action == RETU)
	{
		printf("return (");
		print_res_tree(node->right);
		printf(")");
		return ;
	}
	else
	{
		printf("UNKNOWN ACTION\n");
		exit(1);
	}
	print_res_tree(node->left);
	printf(", ");
	print_res_tree(node->right);
	printf(")");
}

int	main()
{
	top_node = NULL;
	yyparse();
	if (top_node)
	{
		//printf("\n\ntop node has a value\n");
		//printf("action : ");
		//if (top_node->action == INDEX)
		//	printf("INDEX\n");
		//else if (top_node->action == ADD)
		//	printf("ADD\n");
		//else if (top_node->action == END_NODE)
		//	printf("END_NODE\n");

		print_res_tree(top_node);
		//printf("\n");
	}
	else
		printf("\n\ntop node has no value\n");
	return (0);
}

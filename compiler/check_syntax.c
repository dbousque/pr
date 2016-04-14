

#include "resolve_layer.h"

void	check_indentation(t_linked_list *abstracted_layer)
{
	char			indent_char;
	char			char_nb;
	int				last_line_indent_nb;
	int				i;
	int				x;
	t_linked_list	*line;

	char_nb = 0;
	indent_char = 0;
	last_line_indent_nb = 0;
	i = 0;
	while (i < abstracted_layer->len)
	{
		line = ((t_linked_list*)abstracted_layer->elts[i]);
		x = 0;
		while (*((char*)line->elts[x]) == TAB || *((char*)line->elts[x]) == SPACE)
			x++;
		if (x != 0 && i == 0)
		{
			ft_putstr("First line cannot be indented\n");
			exit(1);
		}
		if (x != 0)
		{
			if (indent_char == 0 && char_nb == 0)
			{
				x = 0;
				// check that all characters on first indented line are all the same
				while (*((char*)line->elts[x]) == TAB || *((char*)line->elts[x]) == SPACE)
				{
					if (*((char*)line->elts[x]) != *((char*)line->elts[0]))
					{
						ft_putstr("Bad indentation, mixed spaces and tabs\n");
						exit(1);
					}
					x++;
				}
				last_line_indent_nb = x;
				char_nb = x;
				indent_char = *((char*)line->elts[0]);
			}
			else
			{
				x = 0;
				while (*((char*)line->elts[x]) == TAB || *((char*)line->elts[x]) == SPACE)
				{
					if (*((char*)line->elts[x]) != indent_char)
					{
						ft_putstr("Bad indentation, mixed spaces and tabs\n");
						exit(1);
					}
					x++;
				}
				if (x > last_line_indent_nb && x != last_line_indent_nb + char_nb)
				{
					ft_putstr("Bad indentation\n");
					exit(1);
				}
				last_line_indent_nb = x;
			}
		}
		i++;
	}
}

void	check_parentheses_and_brackets_close(t_linked_list *abstracted_layer)
{
	int				x;
	int				i;
	t_linked_list	*line;
	int				count1;
	int				count2;
	int				count3;
	char			last_open;

	i = 0;
	while (i < abstracted_layer->len)
	{
		line = ((t_linked_list*)abstracted_layer->elts[i]);
		x = 0;
		count1 = 0;
		count2 = 0;
		count3 = 0;
		last_open = 0;
		while (x < line->len)
		{
			if (*((char*)line->elts[x]) == OPEN_PAR)
			{
				last_open = OPEN_PAR;
				count1++;
			}
			else if (*((char*)line->elts[x]) == OPEN_BRACKET)
			{
				last_open = OPEN_BRACKET;
				count2++;
			}
			else if (*((char*)line->elts[x]) == OPEN_CURL_BRAC)
			{
				last_open = OPEN_CURL_BRAC;
				count3++;
			}
			else if (*((char*)line->elts[x]) == CLOSE_PAR)
			{
				if (last_open != OPEN_PAR)
				{
					ft_putstr("Parenthese closed before it should be\n");
					exit(1);
				}
				count1--;
			}
			else if (*((char*)line->elts[x]) == CLOSE_BRACKET)
			{
				if (last_open != OPEN_BRACKET)
				{
					ft_putstr("Bracket closed before it should be\n");
					exit(1);
				}
				count2--;
			}
			else if (*((char*)line->elts[x]) == CLOSE_CURL_BRAC)
			{
				if (last_open != OPEN_CURL_BRAC)
				{
					ft_putstr("Curly bracket closed before it should be\n");
					exit(1);
				}
				count3--;
			}
			if (count1 < 0)
			{
				ft_putstr("Too many closed parentheses\n");
				exit(1);
			}
			if (count2 < 0)
			{
				ft_putstr("Too many closed brackets\n");
				exit(1);
			}
			if (count3 < 0)
			{
				ft_putstr("Too many closed curly brackets\n");
				exit(1);
			}
			x++;
		}
		if (count1 != 0)
		{
			ft_putstr("A parenthese has not been closed\n");
			exit(1);
		}
		if (count2 != 0)
		{
			ft_putstr("A bracket has not been closed\n");
			exit(1);
		}
		if (count3 != 0)
		{
			ft_putstr("A curly bracket has not been closed\n");
			exit(1);
		}
		i++;
	}
}
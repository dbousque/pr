

#include "args_from_c_args.h"

t_variable	*_args_from_c_args(int argc, char **argv)
{
	t_variable		*res;
	t_linked_list	*list;
	int				i;

	list = new_list_start_size(argc - 1);
	i = 1;
	while (i < argc)
	{
		add_to_list(list, _new_string_from_chars(argv[i], ft_strlen(argv[i])));
		i++;
	}
	res = new_var(LINKED_LIST);
	res->val = list;
	return (res);
}
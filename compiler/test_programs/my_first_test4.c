

#include "../../language/language.h"

void		__main(t_variable *args)
{

 ��
}


int		main(int argc, char **argv)
{
	t_variable	*args;

	args = _args_from_c_args(argc, argv);
	__main(args);
	return (0);
}
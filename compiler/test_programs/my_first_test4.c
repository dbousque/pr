

#include "../../language/language.h"

t_variable	*__calcul(t_variable *argu, t_variable *argd, t_variable *argt)
{

	return (_minus(argu, _multiply(argd, argt)));
}


void		__main(t_variable *args)
{
	int i;
	t_variable	*total;

	i = 0;
	total = _new_int(0);
	while (i < 2000000)
	{
		//total +=  *((int*)__calcul(_new_int(5), _new_int(45), _new_int(8))->val);
		_plus_equal(total, _new_int(5 - 45 * 8));
		i++;
	}
	print(total);
}


int		main(int argc, char **argv)
{
	t_variable	*args;

	args = _args_from_c_args(argc, argv);
	__main(args);
	return (0);
}
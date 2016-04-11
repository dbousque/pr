

#include "utils.h"

int		pos_int_str_len(int n)
{
	if (n == 0)
		return (1);
	int		res;

	res = 0;
	while (n > 0)
	{
		n /= 10;
		res += 1;
	}
	return (res);
}
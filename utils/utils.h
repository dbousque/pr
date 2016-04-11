

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

char		*ft_ntoa_base(long long n, char *base);
char		*ft_itoa(long n);
long		ft_strlen(char *str);
int			pos_int_str_len(int n);
long		ft_atoi_with_size(char *str, long len);

#endif
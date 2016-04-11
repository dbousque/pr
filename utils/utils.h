

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <unistd.h>

char		*ft_ntoa_base(long long n, char *base);
char		*ft_itoa(long n);
long		ft_strlen(char *str);
int			pos_int_str_len(int n);
long		ft_atoi_with_size(char *str, long len);
void		ft_putstr(char *str);
char		**split_on_char(char *string, long string_len, char to_split);

#endif
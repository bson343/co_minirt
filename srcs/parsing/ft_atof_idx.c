#include "libft.h"

static int	atoi_endptr(char *str, char **endptr)
{
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		if ((result > 2147483647 && sign == 1) || (result > 2147483648 && sign == -1))
			return (-666);
		str++;
	}
	*endptr = str;
	return ((int)(result * sign));
}

static int	ft_pow(int n, int up)
{
	int cnt;
	int	result;

	cnt = 1;
	if (up == 0)
		return (1);
	result = n;
	while (cnt < up)
	{
		result *= n;
		++cnt;
	}
	return (result);
}

double	ft_atof_idx(char *nptr, int *return_idx)
{
	double		integer;
	double		decimal;
	char		*iter;
	char		*temp;

	iter = nptr + *return_idx;
	decimal = 0.0;
	integer = atoi_endptr(iter, &temp);
	iter = temp;
	if (*iter == '.')
		++iter;
	if (!(*iter >= '0' && *iter <= '9'))
	{
		*return_idx = temp - nptr;
		return (integer);
	}
	decimal = atoi_endptr(iter, &temp);
	*return_idx = temp - nptr;
	return (integer + decimal / ft_pow(10, temp - iter));
}


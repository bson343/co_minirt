#include "minirt.h"

t_bool	check_range(double n, double min, double max)
{
	if (n < min || n > max)
		return (FALSE);
	return (TRUE);
}

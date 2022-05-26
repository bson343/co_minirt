/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bson <bson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:51:50 by bson              #+#    #+#             */
/*   Updated: 2022/05/26 15:51:50 by bson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	is_next_valid(char *str, int *i)
{
	int	idx;

	idx = *i;
	if (str[idx] != ',')
		return (FALSE);
	++idx;
	++(*i);
	while (str[idx] == ' ')
		++idx;
	if (str[idx] == '-' || str[idx] == '+')
		++idx;
	if (str[idx] < '0' || str[idx] > '9')
		return (FALSE);
	return (TRUE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:26:19 by rakhsas           #+#    #+#             */
/*   Updated: 2023/06/12 10:42:57 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	my_atoi(const char *str)
{
	int		i;
	int		sym;
	long	res;

	i = 0;
	sym = 1;
	res = 0;
	str = ft_strtrim(str, " ");
	if (i[str] == '-')
		ft_error("Error\nNegative resolution\n", "");
	if (i[str] == '+' || i[str] == '-')
		i++;
	while (i[str])
	{
		if (!ft_isdigit(i[str]))
			return (-2);
		else if (res * sym > 2147483647)
			return (-1);
		else
			res = res * 10 + (i[str] - '0');
		i++;
	}
	free((char *)str);
	return (sym * res);
}

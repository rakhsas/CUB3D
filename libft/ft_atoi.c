/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:46:15 by aankote           #+#    #+#             */
/*   Updated: 2023/04/06 23:25:13 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t			i;
	unsigned long	my_int;
	int				sign;

	i = 0;
	sign = 1;
	my_int = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
		my_int = my_int * 10 + str[i++] - 48;
	if (my_int >= 9223372036854775807 && sign == 1)
		return (-1);
	if (my_int > 9223372036854775807 && sign == -1)
		return (0);
	return (my_int * sign);
}

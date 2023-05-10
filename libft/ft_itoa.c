/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:52:40 by rakhsas           #+#    #+#             */
/*   Updated: 2023/05/07 16:46:47 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_absolute(int num)
{
	long long	n;

	n = num;
	if (n < 0)
		return (n * -1);
	return (n);
}

static int	ft_length(int num)
{
	int			len;
	long long	sign;

	len = 1;
	sign = ft_absolute(num);
	num /= 10;
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int num)
{
	long long	sign;
	char		*str;
	int			i;
	int			len;
	int			l;

	sign = ft_absolute(num);
	len = ft_length(num);
	l = len;
	i = 0;
	if (num < 0)
		len = ++l;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (num < 0)
		str[i++] = '-';
	while (len > i)
	{
		str[len - 1] = (sign % 10) + '0';
		sign /= 10;
		len--;
	}
	str[l] = '\0';
	return (str);
}

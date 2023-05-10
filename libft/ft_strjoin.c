/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 02:27:57 by rakhsas           #+#    #+#             */
/*   Updated: 2023/05/06 13:40:16 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		x;
	int		y;
	char	*str;
	int		len_of_s1;
	int		len_of_s2;

	if (!s2)
		return (NULL);
	if (s1 == 0)
		s1 = "";
	x = 0;
	y = 0;
	len_of_s1 = ft_strlen(s1);
	len_of_s2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len_of_s1 + len_of_s2 + 1));
	if (!str)
		return (NULL);
	while (x < len_of_s1)
	{
		x[str] = x[s1];
		x++;
	}
	while (y < len_of_s2)
		x++[str] = y++[s2];
	x[str] = '\0';
	return (str);
}

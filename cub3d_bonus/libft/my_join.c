/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 02:27:57 by rakhsas           #+#    #+#             */
/*   Updated: 2023/06/12 12:08:32 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*my_strjoin(char const *s1, char const *s2)
{
	int		x;
	int		y;
	char	*str;

	if (!s2)
		return (NULL);
	if (s1 == 0)
		s1 = "";
	x = 0;
	y = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (x < (int)ft_strlen(s1))
	{
		x[str] = x[s1];
		x++;
	}
	while (y < (int)ft_strlen(s2))
		x++[str] = y++[s2];
	x[str] = '\0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:48:04 by rakhsas           #+#    #+#             */
/*   Updated: 2022/10/30 14:54:58 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (i[s1] && i[s1] == i[s2])
			while (i[s1] && i[s1] == i[s2] && i < n)
				i++;
		else
			return ((unsigned char)i[s1] - (unsigned char)i[s2]);
	}
	return (0);
}

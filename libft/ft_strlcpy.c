/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:03:37 by rakhsas           #+#    #+#             */
/*   Updated: 2022/10/30 14:47:43 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	x = ft_strlen(src);
	while (i[src] && i + 1 < dstsize)
	{
		i[dst] = i[src];
		i++;
	}
	if (dstsize)
		i[dst] = '\0';
	return (x);
}

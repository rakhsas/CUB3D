/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:39:51 by aankote           #+#    #+#             */
/*   Updated: 2023/03/09 20:16:55 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, const char *src, int dstsize)
{
	int	i;
	int	len;
	int	init_len;

	if (!dstsize && !dst)
		return (ft_strlen(src));
	i = 0;
	init_len = ft_strlen(dst);
	len = init_len;
	if (dstsize > len)
	{
		while (src[i] && len < dstsize - 1)
		{
			dst[len] = src[i];
			i++;
			len++;
		}
		dst[len] = '\0';
	}
	if (dstsize > init_len)
		return (ft_strlen(src) + init_len);
	return (ft_strlen(src) + dstsize);
}

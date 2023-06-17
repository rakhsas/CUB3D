/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:10:34 by aankote           #+#    #+#             */
/*   Updated: 2022/10/25 00:05:34 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	if (count && size > SIZE_MAX / count)
		return (0);
	ptr = (char *)malloc(count * size);
	if (ptr)
	{
		ft_bzero(ptr, count * size);
		return (ptr);
	}
	return (0);
}

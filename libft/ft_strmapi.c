/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 03:52:19 by aankote           #+#    #+#             */
/*   Updated: 2022/10/25 01:43:46 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*p;
	unsigned int	i;

	i = 0;
	if (s == NULL || !f)
		return (0);
	p = ft_strdup(s);
	if (p)
	{
		while (s[i])
		{
			p[i] = (*f)(i, ((char *)s)[i]);
			i++;
		}
		return (p);
	}
	return (0);
}

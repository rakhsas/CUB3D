/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:29:58 by aankote           #+#    #+#             */
/*   Updated: 2022/10/25 00:22:38 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	st;
	unsigned int	i;
	char			*substr;

	i = 0;
	st = start;
	if (s == NULL)
		return (0);
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
	{
		substr = (char *)malloc((ft_strlen(s) - start + 1));
		len = ft_strlen(s) - start;
	}
	else
		substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr)
	{
		while (s[st] && st < len + start)
			substr[i++] = s[st++];
		substr[i] = '\0';
		return (substr);
	}
	return (0);
}

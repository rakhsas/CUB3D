/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:07:03 by aankote           #+#    #+#             */
/*   Updated: 2022/11/14 20:07:05 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_l(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr_l(const char *s, int c)
{
	size_t	i;

	i = 0;
	if ((char)c == 0)
		return ((char *)s + ft_strlen_l(s));
	while (i < ft_strlen_l(s))
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}

char	*ft_strjoin_l(char const *s1, char const *s2)
{
	int		i;
	int		j;
	size_t	total_size;
	char	*newstr;

	i = 0;
	j = 0;
	if (!s1)
		return (0);
	total_size = ft_strlen_l(s1) + ft_strlen_l(s2);
	newstr = (char *)malloc(sizeof(char) * (total_size + 1));
	if (!newstr)
		return (0);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j])
		newstr[i++] = s2[j++];
	newstr[i] = '\0';
	return (newstr);
}

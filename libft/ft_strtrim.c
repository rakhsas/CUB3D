/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:56:02 by aankote           #+#    #+#             */
/*   Updated: 2022/10/25 00:37:54 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*trim1(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	test;

	i = 0;
	while (s1[i])
	{
		test = 0;
		j = 0;
		while (set[j])
		{
			if (((char *)set)[j] == ((char *)s1)[i])
				test = 1;
			j++;
		}
		if (i == (int)ft_strlen(s1) - 1)
			return (0);
		if (test == 0)
			return ((char *)s1 + i);
		i++;
	}
	return (0);
}

static int	strend(char const *s1, char const *set)
{
	size_t	i;
	int		j;
	int		test;
	int		cpt;

	i = ft_strlen(s1) - 1;
	cpt = 0;
	while (s1[i] && i >= 0)
	{
		j = 0;
		test = 0;
		while (set[j])
		{
			if (set[j] == s1[i])
				test = 1;
			j++;
		}
		if (test == 0)
			return (cpt);
		i--;
		cpt++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	char	*s;
	size_t	len;
	size_t	i;

	i = 0;
	if (!(char *)s1 || !(char *)set)
		return (0);
	s = trim1(s1, set);
	if (!s)
		return (ft_strdup(""));
	len = ft_strlen(trim1(s1, set)) - strend(s1, set);
	trim = malloc(sizeof(char) * (len + 1));
	if (!trim)
		return (0);
	while (s[i] && i < len)
	{
		trim[i] = s[i];
		i++;
	}
	trim[i] = '\0';
	return (trim);
}

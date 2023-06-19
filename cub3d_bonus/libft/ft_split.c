/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:37:08 by aankote           #+#    #+#             */
/*   Updated: 2023/04/06 21:44:45 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		free(c[i]);
		i++;
	}
	free(c);
	return (NULL);
}

static char	**first_alloc(char const *s, char c)
{
	int		i;
	int		cpt;
	int		test;
	char	**p;

	i = 0;
	test = 0;
	cpt = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c && test == 0)
		{
			test = 1;
			cpt++;
		}
		if (s[i] == c)
			test = 0;
		i++;
	}
	p = (char **)malloc(sizeof(char *) * (cpt + 1));
	return (p);
}

static char	**mini(char const *s, char c, char **p)
{
	size_t	i;
	size_t	k;
	int		start;

	i = 0;
	k = 0;
	start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start == -1)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			p[k++] = ft_substr(s, start, i - start);
			if (!p[k - 1])
				return (ft_free(p));
			start = -1;
		}
		i++;
	}
	p[k] = NULL;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	char	**x;

	p = first_alloc(s, c);
	if (!p)
		return (0);
	x = mini(s, c, p);
	return (x);
}

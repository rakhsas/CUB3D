/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 02:51:10 by rakhsas           #+#    #+#             */
/*   Updated: 2022/10/30 17:02:21 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_searcher(char c, char const *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		first;
	int		i;
	int		last;
	char	*trim;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	last = ft_strlen (s1);
	first = 0;
	while (s1[first] && ft_searcher(s1[first], set))
		first++;
	while (last > first && ft_searcher(s1[last - 1], set))
		last--;
	trim = (char *)malloc(sizeof (char) * (last - first + 1));
	if (trim == 0)
		return (NULL);
	while (first < last)
		trim[i++] = s1[first++];
	trim[i] = '\0';
	return (trim);
}

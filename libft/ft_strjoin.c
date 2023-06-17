/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:17:19 by aankote           #+#    #+#             */
/*   Updated: 2023/03/31 01:21:12 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	size_t	total_size;
	char	*newstr;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	total_size = ft_strlen(s1) + ft_strlen(s2);
	newstr = malloc(sizeof(char) * (total_size + 1));
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

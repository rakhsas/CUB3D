/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 21:05:58 by rakhsas           #+#    #+#             */
/*   Updated: 2022/10/31 14:20:43 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	count;
	size_t	len_of_needle;
	char	*hs;

	hs = (char *)haystack;
	len_of_needle = ft_strlen(needle);
	if (len_of_needle == 0 && haystack == needle)
		return (hs);
	i = 0;
	if (len_of_needle == 0)
		return (hs);
	while (i < len && i[hs] != '\0')
	{
		count = 0;
		while (hs[i + count] != '\0' && needle[count] != '\0'
			&& hs[i + count] == needle[count] && (i + count) < len)
		{
			count++;
			if (count == len_of_needle)
				return (hs + i);
		}
		i++;
	}
	return (NULL);
}

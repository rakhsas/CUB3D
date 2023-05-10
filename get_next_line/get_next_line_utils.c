/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:10:07 by rakhsas           #+#    #+#             */
/*   Updated: 2023/05/04 16:45:19 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlenn(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (i[str])
		i++;
	return (i);
}

char	*save(char *str)
{
	int		i;
	int		j;
	char	*rts;

	i = 0;
	while (i[str] && i[str] != '\n')
		i++;
	if (!str[i])
		return (free_it(str));
	rts = malloc(ft_strlenn(str) - i + 1);
	if (!rts)
		return (NULL);
	i++;
	j = 0;
	while (i[str])
		rts[j++] = str[i++];
	rts[j] = '\0';
	free(str);
	return (rts);
}

int	check_newline1(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (i[str])
	{
		if (i[str] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (dst == src)
		return (dst);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dst);
	}
	while (len--)
		*d++ = *s++;
	return (dst);
}

char	*str_join(char const	*str, char const	*rts)
{
	size_t	str_len;
	size_t	rts_len;
	size_t	total_len;
	char	*joined_string;

	if (!str && !rts)
		return (NULL);
	str_len = ft_strlenn((char *)str);
	rts_len = ft_strlenn((char *)rts);
	total_len = str_len + rts_len + 1;
	joined_string = malloc(total_len);
	if (!joined_string)
		return (NULL);
	ft_memmove(joined_string, str, str_len);
	ft_memmove(joined_string + str_len, rts, rts_len);
	joined_string[total_len - 1] = '\0';
	free((char *)str);
	return (joined_string);
}

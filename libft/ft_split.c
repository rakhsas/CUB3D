/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:13:30 by rakhsas           #+#    #+#             */
/*   Updated: 2022/10/31 19:21:23 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(char const *word, char c)
{
	int	strs;

	strs = 0;
	while (*word)
	{
		if (*word != c)
		{
			strs++;
			while (*word && *word != c)
				word++;
		}
		else
			word++;
	}
	return (strs);
}

static char	*ft_string_cpy(char *word, char const *s, int j, int word_len)
{
	int	i;

	i = 0;
	while (word_len > 0)
	{
		word[i++] = s[j - word_len--];
	}
	word[i] = '\0';
	return (word);
}

static char	**ft_free(char **str, int word_len)
{
	int	i;

	i = 0;
	while (i < word_len)
		free(str[i++]);
	free(str);
	return (0);
}

static char	**ft_split_next(char **str, char const *s, char c, int word_index)

{
	int	i;
	int	j;
	int	word_len;

	i = 0;
	j = 0;
	word_len = 0;
	while (s[j] && i < word_index)
	{
		while (s[j] && s[j] == c)
			j++;
		while (s[j] && s[j] != c)
		{
			j++;
			word_len++;
		}
		str[i] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!str)
			return (ft_free(str, i));
		ft_string_cpy(str[i], s, j, word_len);
		word_len = 0;
		i++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		word_num;

	if (!s)
		return (NULL);
	word_num = ft_counter(s, c);
	str = (char **)malloc(sizeof(char *) * (word_num + 1));
	if (!str)
		return (NULL);
	ft_split_next(str, s, c, word_num);
	return (str);
}

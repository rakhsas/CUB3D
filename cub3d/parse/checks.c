/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:19:35 by rakhsas           #+#    #+#             */
/*   Updated: 2023/06/12 18:10:00 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_infos_from_map(t_map *s_map)
{
	int	i;

	i = 0;
	s_map->c_tab = ft_calloc (sizeof(char *) * 7, 1);
	while (i < 6 && s_map->map[i])
	{
		s_map->c_tab[i] = s_map->map[i];
		i++;
	}
}

char	*ft_strtrim_free(char *str, char *rts)
{
	char	*tmp;

	if (!str)
		return (NULL);
	tmp = ft_strtrim(str, rts);
	free(str);
	return (tmp);
}

int	bubble_sort(char **s1)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = i + 1;
		while (s1[j])
		{
			if (ft_strncmp(s1[i], s1[j], 2) == 0)
				return (-1);
			break ;
		}
		i++;
	}
	return (0);
}

void	check_for_max_255(char	*str, int *c_p)
{
	char	**tab;
	int		i;
	int	number;

	i = 0;
	if (ft_isdigit(str[ft_strlen(str) - 1]) == 0)
		ft_error("Error\nRGB values cannot contain special characters\n", "");
	tab = ft_split(str + 2, ',');
	free(str);
	while (tab[i])
	{
		number = ft_atoi(tab[i]);
		if (number == -2)
			ft_error("Error\nRGB values must be numbers\n", "");
		else if (number > 255 || number < 0)
			ft_error("Error\nRGB values must be between 0 and 255\n", "");
		else
			c_p[i] = number;
		free (tab[i]);
		i++;
	}
	free(tab);
	if (i > 3)
		ft_error("Error\nRGB expecte 3 arguments\n", "");
}

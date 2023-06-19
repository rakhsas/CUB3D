/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extensions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:46:59 by rakhsas           #+#    #+#             */
/*   Updated: 2023/06/12 11:05:21 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_extension(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	if (ft_strncmp(".cub", str + len - 4, 4) != 0)
		return (-1);
	return (1);
}

void	check_for_textures_extension(t_map *s_map)
{
	if (ft_strncmp(s_map->so + ft_strlen(s_map->so) - 4, ".xpm", 4) != 0)
		ft_error("Error\nSO texture must be a .xpm file\n", "");
	if (ft_strncmp(s_map->no + ft_strlen(s_map->no) - 4, ".xpm", 4) != 0)
		ft_error("Error\nNO texture must be a .xpm file\n", "");
	if (ft_strncmp(s_map->we + ft_strlen(s_map->we) - 4, ".xpm", 4) != 0)
		ft_error("Error\nWE texture must be a .xpm file\n", "");
	if (ft_strncmp(s_map->ea + ft_strlen(s_map->ea) - 4, ".xpm", 4) != 0)
		ft_error("Error\nEA texture must be a .xpm file\n", "");
}

int	simplify(char *c_tab, char *s2, char **get_data, int len)
{
	if (ft_strncmp(c_tab, s2, len) == 0)
	{
		get_data[0] = test(c_tab);
		return (1);
	}
	return (0);
}

void	get_specified_data(t_map *s_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (bubble_sort(s_map->c_tab) == -1)
		ft_error("Error\n", "Invalid data\n");
	while (s_map->c_tab[i])
	{
		j += simplify(s_map->c_tab[i], "SO ", &s_map->so, 3);
		j += simplify(s_map->c_tab[i], "NO ", &s_map->no, 3);
		j += simplify(s_map->c_tab[i], "WE ", &s_map->we, 3);
		j += simplify(s_map->c_tab[i], "EA ", &s_map->ea, 3);
		j += simplify(s_map->c_tab[i], "C ", &s_map->c, 2);
		j += simplify(s_map->c_tab[i], "F ", &s_map->f, 2);
		i++;
	}
	if (j < 6)
		ft_error("Error\n", "Missing data\n");
	else if (j > 6)
		ft_error("Error\n", "Too much data\n");
}

void	check_for_unwanted_chars(t_map *s_map)
{
	int	i;
	int	j;

	i = 0;
	while (s_map->map[i])
	{
		j = 0;
		while (s_map->map[i][j])
		{
			if (s_map->map[i][j] != '1' && s_map->map[i][j] != '0'
				&& s_map->map[i][j] != 'N' && s_map->map[i][j] != 'S'
				&& s_map->map[i][j] != 'W' && s_map->map[i][j] != 'E'
				&& s_map->map[i][j] != ' ')
				ft_error("Error\nUnwanted character in map\n", "");
			j++;
		}
		i++;
	}
}

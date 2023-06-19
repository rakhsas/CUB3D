/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vulnerabilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 10:21:38 by rakhsas           #+#    #+#             */
/*   Updated: 2023/06/12 11:08:40 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_check_left_bottom(t_map *s_map, int i, int j, int action)
{
	while (j >= 0 && i >= 0 && s_map->map_copy[i][j])
	{
		if (s_map->map_copy[i][j] != '1' && s_map->map_copy[i][j] != ' ')
			return (1);
		else if (s_map->map_copy[i][j] == '1')
			break ;
		if (action)
			i--;
		else
			j--;
	}
	return (0);
}

int	ft_check_right_top(t_map *s_map, int i, int j, int action)
{
	while (s_map->map_copy[i] && s_map->map_copy[i][j])
	{
		if (s_map->map_copy[i][j] != '1' && s_map->map_copy[i][j] != ' ')
			return (1);
		else if (s_map->map_copy[i][j] == '1')
			break ;
		if (action)
			i++;
		else
			j++;
	}
	return (0);
}

void	check_if_spaces(t_map *s_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s_map->map_copy[i])
	{
		j = 0;
		while (s_map->map_copy[i][j])
		{
			if (s_map->map_copy[i][j] == ' ' || i == 0
				|| j == 0 || !s_map->map_copy[i + 1]
				|| !s_map->map_copy[i][j + 1])
			{
				if (ft_check_right_top(s_map, i, j, 1)
					|| ft_check_right_top(s_map, i, j, 0)
					|| ft_check_left_bottom(s_map, i, j, 1)
					|| ft_check_left_bottom(s_map, i, j, 0))
					ft_error("Error\nMap is not closed ('Spaces')\n", "");
			}
			j++;
		}
		i++;
	}
}

void	make_the_map_rectangle(t_map *s_map, int max)
{
	int	i;
	int	j;

	i = 0;
	while (s_map->map_copy[i])
	{
		j = ft_strlen(s_map->map_copy[i]);
		while (max > j)
		{
			s_map->map_copy[i] = free_join(s_map->map_copy[i], " ");
			j++;
		}
		i++;
	}
	check_if_spaces(s_map);
}

int	get_max_len(t_map *s_map)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	max = 0;
	while (s_map->map[i])
	{
		j = 0;
		while (s_map->map[i][j])
			j++;
		if (j > max)
			max = j;
		i++;
	}
	return (max);
}

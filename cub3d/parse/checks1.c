/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:21:18 by rakhsas           #+#    #+#             */
/*   Updated: 2023/06/17 10:40:05 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_border_top(t_map *s_map)
{
	int	i;

	i = 0;
	while (s_map->map[0] && s_map->map[0][i])
	{
		if (s_map->map[0][i] != '1' && s_map->map[0][i] != ' ')
			ft_error("Error\nMap error\n", "");
		i++;
	}
}

void	get_map(t_map *s_map)
{
	int	i;

	i = 0;
	while (s_map->map[i])
		i++;
	s_map->height = i;
	s_map->map_copy = (char **)ft_calloc(s_map->height + 1, sizeof(char *));
	i = 0;
	while (s_map->map[i])
	{
		s_map->map_copy[i] = ft_strdup(s_map->map[i]);
		i++;
	}
}
void	check_textures(t_map *s_map)
{
	check_for_textures_extension(s_map);
	check_for_textures_path(s_map);
}

void	parse_first_part(t_map *s_map, int fd)
{
	int	i;

	i = 0;
	s_map->map = fill_map(fd);
	init(s_map);
	get_infos_from_map(s_map);
	get_specified_data(s_map);
	skip_useless_data(s_map);
	check_for_max_255(s_map->f, s_map->c_p);
	check_for_max_255(s_map->c, s_map->f_p);
	check_textures(s_map);
	s_map->map += 6;
	check_border_top(s_map);
	check_for_unwanted_chars(s_map);
	init_sec_part(s_map);
	get_map(s_map);
	make_the_map_rectangle(s_map, get_max_len(s_map));

}

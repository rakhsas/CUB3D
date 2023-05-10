/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:40:30 by rakhsas           #+#    #+#             */
/*   Updated: 2023/05/09 16:55:46 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

void	parse(char **map)
{
	int	i;

	i = 0;
	if (check_for_chars(map[i]) == -1)
		return ;
	while (map[i])
	{
		if (map[i][0] != '1' || ft_strlen(map[i]) != '1')
			printf("Error\n");
		i++;
	}
}

char	*join_free(char *s1, char *s2)
{
	char	*tmp;
	char	*tmp1;

	tmp = s1;
	tmp1 = ft_strjoin(tmp, s2);
	free(s1);
	return (tmp1);
}

void	fill_map2(int *i, char **line, char **s1)
{
	if (i[0] < 7)
	{
		line[0] = ft_strtrim_free(line[0], " ");
		if ((line[0][0] == '1' || line[0][0] == ' ' || line[0][0] == '0')
			&& (line[0][1] == '1' || line[0][1] == ' ' || line[0][1] == '0'))
			ft_error("Error\n", "Map content has to be at the end of file\n");
		s1[0] = join_free(s1[0], line[0]);
		free(line[0]);
	}
	else
	{
		s1[0] = join_free(s1[0], line[0]);
		free(line[0]);
	}
}

char	**fill_map(int fd)
{
	int		i;
	char	*line;
	char	*s1;
	char	**map;

	i = 0;
	s1 = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			free(line);
			break ;
		}
		fill_map2(&i, &line, &s1);
		i++;
	}
	map = ft_split(s1, '\n');
	free(s1);
	return (map);
}

void	initialize_sec_part(t_map *s_map)
{
	int	i;
	int	j;

	i = 0;
	if (!s_map->map)
		ft_error("Error\nMap is empty\n", "");
	while (s_map->map[i])
	{
		j = 0;
		while (s_map->map[i][j++])
		{
			if (s_map->map[i][j] == 'N' || s_map->map[i][j] == 'S'
				|| s_map->map[i][j] == 'W' || s_map->map[i][j] == 'E')
			{
				if (s_map->player->p_posx != -1 || s_map->player->p_posy != -1)
					ft_error("Error\nMultiple players\n", "");
				s_map->player->p_posx = j;
				s_map->player->p_posy = i;
				s_map->player->p_dir = s_map->map[i][j];
			}
		}
		i++;
	}
	if (s_map->player->p_posx == -1 || s_map->player->p_posy == -1)
		ft_error("Error\nPlayer is missing\n", "");
}

void	check_border_top(t_map *s_map)
{
	int	i;

	i = 0;
	while (s_map->map[0][i])
	{
		if (s_map->map[0][i] == ' ')
		{
			i++;
			continue ;
		}
		else if (s_map->map[0][i] != '1')
			ft_error("Error\nMap is not closed ('Top Border')\n", "");
		i++;
	}
}

void	check_border_left(t_map *s_map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (s_map->map[len])
		len++;
	i = 1;
	while (len - 1 >= i)
	{
		while(s_map->map[i][j] == ' ')
			j++;
		if (s_map->map[i][j] != '1')
			ft_error("Error\nMap is not closed ('Left Border')\n", "");
		j = 0;
		i++;
	}
}

void	check_border_right(t_map *s_map)
{
	int	i;
	int	j;

	i = 0;
	while (s_map->map[i])
	{
		j = ft_strlen(s_map->map[i]) - 1;
		while (s_map->map[i][j] == ' ')
			j--;
		if (s_map->map[i][j] != '1')
			ft_error("Error\nMap is not closed ('Right Border')\n", "");
		i++;
	}
}

void	check_border_bottom(t_map *s_map)
{
	int	i;
	int	j;

	i = 0;
	while (s_map->map[i])
		i++;
	i--;
	j = 0;
	while (s_map->map[i][j])
	{
		if (s_map->map[i][j] != '1' && s_map->map[i][j] != ' ')
			ft_error("Error\nMap is not closed ('Bottom Border')\n", "");
		j++;
	}

}

void	check_map_borders(t_map *s_map)
{
	check_border_top(s_map);
	check_border_bottom(s_map);
	check_border_left(s_map);
	check_border_right(s_map);
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

void	parse_first_part(t_map *s_map, int fd)
{
	s_map->map = fill_map(fd);
	initialize(s_map);
	get_infos_from_map(s_map);
	get_specified_data(s_map);
	skip_useless_data(s_map);
	check_for_max_255(s_map->f, s_map->c_p);
	check_for_max_255(s_map->c, s_map->f_p);
	check_for_textures_extension(s_map);
	check_for_textures_path(s_map);
	s_map->map += 6;
	// check_for_unwanted_chars(s_map);
	initialize_sec_part(s_map);
	check_map_borders(s_map);
}

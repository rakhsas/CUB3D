/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:40:30 by rakhsas           #+#    #+#             */
/*   Updated: 2023/06/14 18:37:37 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

char	*free_join(char *s1, char *s2)
{
	char	*tmp;
	char	*tmp1;

	tmp = s1;
	tmp1 = my_strjoin(tmp, s2);
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
		s1[0] = free_join(s1[0], line[0]);
		free(line[0]);
	}
	else
	{
		s1[0] = free_join(s1[0], line[0]);
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
	if (i == 0)
		ft_error("Error\nMap is empty\n", "");
	map = ft_split(s1, '\n');
	close(fd);
	free(s1);
	return (map);
}

void	init_sec_part(t_map *s_map)
{
	int	i;
	int	j;

	i = 0;
	while (s_map->map[i])
	{
		j = 0;
		while (s_map->map[i][j])
		{
			if (s_map->map[i][j] == 'N' || s_map->map[i][j] == 'S'
				|| s_map->map[i][j] == 'W' || s_map->map[i][j] == 'E')
			{
				if (s_map->player->p_posx != -1 || s_map->player->p_posy != -1)
					ft_error("Error\nMultiple players\n", "");
				s_map->player->p_posx = i;
				s_map->player->p_posy = j;
				s_map->player->p_dir = s_map->map[i][j];
			}
			j++;
		}
		i++;
	}
	if (s_map->player->p_posx == -1 || s_map->player->p_posy == -1)
		ft_error("Error\nPlayer is missing\n", "");
}

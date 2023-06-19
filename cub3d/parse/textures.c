/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:46:51 by rakhsas           #+#    #+#             */
/*   Updated: 2023/06/14 18:38:11 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void	check_for_textures_path(t_map *s_map)
{
	s_map->ea += 3;
	s_map->no += 3;
	s_map->so += 3;
	s_map->we += 3;
	s_map->textures->ea = open(s_map->ea, O_RDONLY);
	s_map->textures->no = open(s_map->no, O_RDONLY);
	s_map->textures->so = open(s_map->so, O_RDONLY);
	s_map->textures->we = open(s_map->we, O_RDONLY);
	if (s_map->textures->ea < 0)
		ft_error("Error\nEA texture path is invalid\n", "");
	if (s_map->textures->no < 0)
		ft_error("Error\nNO texture path is invalid\n", "");
	if (s_map->textures->so < 0)
		ft_error("Error\nSO texture path is invalid\n", "");
	if (s_map->textures->we < 0)
		ft_error("Error\nWE texture path is invalid\n", "");
	close(s_map->textures->ea);
	close(s_map->textures->no);
	close(s_map->textures->so);
	close(s_map->textures->we);
}

void	skip_useless_data(t_map *s_map)
{
	if (s_map->so == NULL)
		(ft_error("Error\nMissing SO texture\n", ""));
	if (s_map->no == NULL)
		(ft_error("Error\nMissing NO texture\n", ""));
	if (s_map->we == NULL)
		(ft_error("Error\nMissing WE texture\n", ""));
	if (s_map->ea == NULL)
		(ft_error("Error\nMissing EA texture\n", ""));
	if (s_map->f == NULL)
		(ft_error("Error\nMissing Floor color\n", ""));
	if (s_map->c == NULL)
		(ft_error("Error\nMissing Ceiling color\n", ""));
	s_map->so = ft_strtrim_free(s_map->so, " ");
	s_map->no = ft_strtrim_free(s_map->no, " ");
	s_map->we = ft_strtrim_free(s_map->we, " ");
	s_map->ea = ft_strtrim_free(s_map->ea, " ");
	s_map->f = ft_strtrim_free(s_map->f, " ");
	s_map->c = ft_strtrim_free(s_map->c, " ");
}

int	check_for_chars(char *line)
{
	int	i;
	int	fd;

	i = 0;
	if (line[i] != 'N' || line[i + 1] != 'O')
	{
		printf("Error\n");
		return (-1);
	}
	i = i + 3;
	fd = open(line + i, O_RDONLY);
	if (fd < 0)
	{
		printf("Invalid texture Path\n");
		return (-1);
	}
	close(fd);
	return (0);
}

void	init(t_map *s_map)
{
	s_map->player->p_posx = -1;
	s_map->player->p_posy = -1;
	s_map->so = NULL;
	s_map->no = NULL;
	s_map->we = NULL;
	s_map->ea = NULL;
	s_map->f = NULL;
	s_map->c = NULL;
}

char	*test(char *str)
{
	int		i;
	char	**tab;
	char	*joined;

	i = 0;
	joined = ft_calloc(1, 1);
	// printf("str = %s\n", str);
	tab = ft_split(str, ' ');
	while (tab[i])
	{
		joined = free_join(joined, tab[i]);
		if (tab[i + 1])
			joined = free_join(joined, " ");
		free(tab[i]);
		i++;
	}
	free(tab);
	if (i > 2)
	{
		ft_error("Error\nin: ", str);
	}
	return (joined);
}

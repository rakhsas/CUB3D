/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:14:15 by rakhsas           #+#    #+#             */
/*   Updated: 2023/05/09 09:38:01 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int ac, char **argv)
{
	int		fd;
	t_map	*s_map;

	if (ac == 2)
	{
		s_map = malloc(sizeof(t_map));
		s_map->player = malloc(sizeof(t_player));
		s_map->textures = malloc(sizeof(t_textures));
		fd = open(argv[1], O_RDONLY);
		if (check_extension(argv[1]) == -1)
			ft_error("Error\nFile must be .cub\n", "");
		else if (fd == -1)
			ft_error("Error\nFile not found\n", "");
		else
			parse_first_part(s_map, fd);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:49:42 by rakhsas           #+#    #+#             */
/*   Updated: 2023/05/07 16:33:06 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "string.h"
#include "fcntl.h"

int main(int ac, char **argv, char **env)
{
	int		fd;
	t_map	*s_map;

	if (ac ==  2)
	{
		s_map = malloc(sizeof(t_map));
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			write(2, "Invalid file\n", 13);
			exit(EXIT_FAILURE);
		}
		if (check_extension(argv[1]) == -1)
			return (0);
		else
		{
			s_map->map = fill_map(fd);
			initialize(s_map);
			get_angle(s_map);
			// s_map->mlx = mlx_init();
			s_map->win = mlx_new_window(s_map->mlx, 1200, 1200, "Cub3D");
			mlx_key_hook(s_map->win, key_hook, s_map);
			mlx_hook(s_map->win, 17, 0, mouse, s_map);
			mlx_loop(s_map->mlx);
			int x;
			for (x = 0; x < 160; x++) {
				int wall_height = get_view()[x];
				vline(x, 80 - (wall_height / 2), wall_height);
			}
		}
		let c = 0;
	}
}
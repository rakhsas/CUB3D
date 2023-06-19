/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:13:07 by aankote           #+#    #+#             */
/*   Updated: 2023/06/19 11:45:10 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_img	*new_img(t_data *data, char *path)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		ft_error("Error\nMalloc failed\n", "");
	img->img = mlx_xpm_file_to_image(data->win.mlx,
			path, &img->width, &img->height);
	img->addr = mlx_get_data_addr(img->img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	return (img);
}

void	seconde_part(t_data *data, t_map *s_map)
{
	t_win	window;

	data->map = s_map;
	data->wall.ceiling_color = (s_map->f_p[0] << 16
			| (s_map->f_p[1] << 8) | (s_map->f_p[2]));
	data->wall.floor_color = (s_map->c_p[0] << 16
			| (s_map->c_p[1] << 8) | (s_map->c_p[2]));
	create_window(&window, data);
	data->map->textures->ea_img = new_img(data, data->map->ea);
	data->map->textures->so_img = new_img(data, data->map->so);
	data->map->textures->we_img = new_img(data, data->map->we);
	data->map->textures->no_img = new_img(data, data->map->no);
	get_dimensions(data);
	data->player.turn_dir = 0;
	data->player.walk_dir = 0;
	create_map(data);
	mlx_hook(data->win.mlx_win, 17, 0, &ft_exit, NULL);
	mlx_hook(window.mlx_win, 2, 0, ft_key_hook, data);
	mlx_hook(data->win.mlx_win, 4, 0, &ft_mouse, data);
	mlx_loop(window.mlx);
}

int	main(int ac, char **av)
{
	t_data	*data;
	t_map	*s_map;
	int		fd;

	if (ac != 2)
		ft_error("Error\nNo map file\n", "");
	data = (t_data *)malloc(sizeof(t_data));
	s_map = malloc(sizeof(t_map));
	s_map->player = malloc(sizeof(t_pl));
	s_map->textures = malloc(sizeof(t_textures));
	fd = open(av[1], O_RDONLY, 0777);
	if (check_extension(av[1]) == -1)
		ft_error("Error\nFile must be .cub\n", "");
	else if (fd == -1)
		ft_error("Error\nFile not found\n", "");
	else
		parse_first_part(s_map, fd);
	seconde_part(data, s_map);
}

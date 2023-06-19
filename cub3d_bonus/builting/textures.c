/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:49:36 by rakhsas           #+#    #+#             */
/*   Updated: 2023/06/19 11:55:47 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	generate_3d(t_data *data, int x)
{
	int		distance_center_wall;
	int		correspanding_y_coordinate;
	t_img	*tex;
	int		j;
	char	*dst;

	j = 0;
	tex = malloc(sizeof(t_img));
	configure_data(data, tex);
	while (j < data->wall.topwall)
		my_mlx_pixel_put(&data->main_img, x, j++, data->wall.ceiling_color);
	while (j < data->wall.bottomwall)
	{
		distance_center_wall = j + (data->wall.heightwall / 2) - (WIN_Y / 2);
		correspanding_y_coordinate = (int)(distance_center_wall
				* (float)tex->height / data->wall.heightwall)
			% tex->height;
		dst = tex->addr + correspanding_y_coordinate * tex->line_length
			+ data->wall.texture_x * (tex->bits_per_pixel / 8);
		my_mlx_pixel_put(&data->main_img, x, j, *(unsigned int *)dst);
		j++;
	}
	while (j < WIN_Y)
		my_mlx_pixel_put(&data->main_img, x, j++, data->wall.floor_color);
	free(tex);
}

void	do_projection(t_data *data, int x, double ds)
{
	ds = ds * cos(data->player.ray_angle - data->player.routation_ang);
	data->wall.heightwall = (CARE / ds) * data->wall.distanceprojplane;
	data->wall.topwall = ((WIN_Y / 2) - (data->wall.heightwall / 2));
	if (data->wall.topwall < 0)
		data->wall.topwall = 0;
	data->wall.bottomwall = ((WIN_Y / 2) + (data->wall.heightwall / 2));
	if (data->wall.bottomwall > WIN_Y)
		data->wall.bottomwall = WIN_Y;
	generate_3d(data, x);
}

void	configure_data(t_data *data, t_img *tex)
{
	if (data->wall.is_horiz_hit)
	{
		if (data->player.ray_angle > rad(0)
			&& data->player.ray_angle <= rad(180))
			*tex = *(data->map->textures->no_img);
		else
			*tex = *(data->map->textures->so_img);
		data->wall.texture_x = (int)(data->ray.xhit
				* tex->width / CARE) % tex->width;
	}
	else
	{
		if (data->player.ray_angle > rad(90)
			&& data->player.ray_angle <= rad(270))
			*tex = *(data->map->textures->we_img);
		else
			*tex = *(data->map->textures->ea_img);
		data->wall.texture_x = (int)(data->ray.yhit
				* tex->width / CARE) % tex->width;
	}
}

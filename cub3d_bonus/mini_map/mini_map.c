/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:12:05 by aankote           #+#    #+#             */
/*   Updated: 2023/06/19 14:41:06 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	draw_squart(t_data *data, int x, int y)
{
	int	x0;
	int	y0;

	y0 = y;
	while (y < y0)
	{
		x0 = x;
		while (x0 < x + CARE)
		{
			if (data->map->map_copy[y / CARE][x / CARE] == '1')
				my_mlx_pixel_put(&data->main_img, x0 ++, y, WALL);
			else if (data->map->map_copy[y / CARE][x / CARE] == '0'
				|| is_player(data->map->map_copy[y / CARE][x / CARE]))
				my_mlx_pixel_put(&data->main_img, x0 ++, y, WAY);
			else
				x0 ++;
		}
		y ++;
	}
	return (0);
}

int	draw_lines(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->win.map_y)
	{
		x = 0;
		while (x < data->win.map_x)
		{
			if (x % CARE == 0 || y % CARE == 0)
				my_mlx_pixel_put(&data->main_img, x, y, LINE);
			x ++;
		}
		y ++;
	}
	return (0);
}

int	draw_player(t_data *data)
{
	int	x;
	int	y;

	y = MAP_Y / 2;
	while (y < MAP_Y / 2 + P_SIZE)
	{
		x = MAP_X / 2;
		while (x < MAP_X / 2 + P_SIZE)
			my_mlx_pixel_put(&data->main_img, x++, y, RED);
		y ++;
	}
	return (0);
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;
	int	mx;
	int	my;

	my = (data->player.py_pos / 4 - MAP_Y / 2) - 8;
	y = -1;
	while (++y < MAP_Y)
	{
		x = -1;
		mx = (data->player.px_pos / 4 - MAP_X / 2) - 8;
		while (++x < MAP_X)
		{
			if ((mx + 8) / 16 >= 0 && (my + 8) / 16 >= 0 && (mx + 8)
				< data->win.map_x / 4 && (my + 8) < data->win.map_y / 4)
			{
				if (data->map->map_copy[(my + 8) / 16][(mx + 8) / 16] == '1')
					my_mlx_pixel_put(&data->main_img, x, y, WALL);
				else
					my_mlx_pixel_put(&data->main_img, x, y, 0xF1F1C1);
			}
			else
				my_mlx_pixel_put(&data->main_img, x, y, 0xF1F1C1);
			(mx)++;
		}
		my ++;
	}
}

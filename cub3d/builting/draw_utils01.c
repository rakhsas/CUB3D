/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:40:42 by aankote           #+#    #+#             */
/*   Updated: 2023/06/18 18:56:15 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void get_dimensions(t_data *data)
{
    int x;
    int y;

    y = 0;
	while(data->map->map_copy[y])
	{
		x = 0;
		while(data->map->map_copy[y][x])
			x ++;
		y++;
	}
	 data->win.map_x = x * CARE;
	 data->win.map_y = y * CARE;
}

void set_reg(t_data *data, int x, int y)
{
	if(data->map->map_copy[y][x] == 'N')
		data->player.routation_ang =  rad(270);
	if(data->map->map_copy[y][x] == 'S')
		data->player.routation_ang =  rad(90);
	if(data->map->map_copy[y][x] == 'E')
		data->player.routation_ang =  rad(0);
	if(data->map->map_copy[y][x] == 'W')
		data->player.routation_ang =  rad(180);
	data->player.turn_dir = 0;
}

void get_player_pos(t_data *data)
{
	int x;
	int y;

	y = 0;
	while(data->map->map_copy[y])
	{
		x = 0;
		while(data->map->map_copy[y][x])
		{
			if(is_player(data->map->map_copy[y][x]))
				break;
			x ++;
		}
		if(is_player(data->map->map_copy[y][x]))
			break;
		y ++;
	}
	data->player.px_pos = x * CARE + 2;
	data->player.py_pos = y * CARE + 2;
	set_reg(data,x, y);
}

double rad(double deg)
{
	return (deg * PI / 180);
}

double deg(double rad)
{
	return (rad * 180  / PI);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:40:42 by aankote           #+#    #+#             */
/*   Updated: 2023/06/15 11:12:17 by rakhsas          ###   ########.fr       */
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
	data->player.px_pos = x * CARE;
	data->player.py_pos = y * CARE;
}

double rad(double deg)
{
	return (deg * PI / 180);
}

double deg(double rad)
{
	return (rad * 180  / PI);
}
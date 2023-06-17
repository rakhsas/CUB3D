/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intersictions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:10:35 by aankote           #+#    #+#             */
/*   Updated: 2023/06/16 16:51:42 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	check_intersictions(t_data *data)
{
	double	hor_line;
	double	ver_line;
	double	ds;

	(hit_hor_wall(data), hit_ver_wall(data));
	data->cords.hor_dx = data->cords.xb_hor - data->player.px_pos;
	data->cords.hor_dy = data->cords.yb_hor - data->player.py_pos;
	data->cords.ver_dx = data->cords.xb_ver - data->player.px_pos;
	data->cords.ver_dy = data->cords.yb_ver - data->player.py_pos;
	hor_line = sqrt(pow(data->cords.hor_dx, 2) + pow(data->cords.hor_dy, 2));
	ver_line = sqrt(pow(data->cords.ver_dx, 2) + pow(data->cords.ver_dy, 2));
	if (hor_line <= ver_line)
	{
		ds = hor_line;
		data->ray.yhit = data->cords.yb_hor;
		data->ray.xhit = data->cords.xb_hor;
		data->wall.is_horiz_hit = 1;
	}
	else
	{
		ds = ver_line;
		data->ray.yhit = data->cords.yb_ver;
		data->ray.xhit = data->cords.xb_ver;
	}
	return (ds);
}

void	draw_rays(t_data *data)
{
	int	x;

	x = 0;
	data->player.ray_angle = data->player.routation_ang - rad(30);
	if (data->player.routation_ang <= 0.1 && data->player.routation_ang >= 0)
		data->player.ray_angle = rad(330);
	while (x < WIN_X)
	{
		check_intersictions(data);
		data->player.ray_angle += rad(60) / WIN_X;
		x ++;
	}
}

void	draw_things(t_data *data)
{
	int		x;
	double	ds;

	x = 0;
	if (data->player.routation_ang <= 0.1 && data->player.routation_ang >= 0)
		data->player.ray_angle = rad(330);
	data->player.ray_angle = data->player.routation_ang - rad(30);
	data->wall.distanceProjPlane = fabs((WIN_X / 2) * tan(rad(30)));
	while (x < WIN_X)
	{
		ds = check_intersictions(data);
		do_projection(data, x, ds);
		data->wall.is_horiz_hit = 0;
		data->player.ray_angle += rad(60) / WIN_X;
		x ++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:36:56 by aankote           #+#    #+#             */
/*   Updated: 2023/06/18 21:00:26 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int update_walk(t_data *data)
{
	data->player.movestep = data->player.walk_dir * MOVE_SPEED;
	data->player.px_pos += cos(data->player.routation_ang) * data->player.movestep;
	data->player.py_pos += sin(data->player.routation_ang) * data->player.movestep;
	initializ(data);
	return (0);
}

int update_walk_rl(t_data *data)
{
	data->player.movestep = data->player.walk_dir * MOVE_SPEED;
	data->player.px_pos += cos(data->player.routation_ang + rad(90)) * data->player.movestep;
	data->player.py_pos += sin(data->player.routation_ang + rad(90)) * data->player.movestep;
	initializ(data);
	return (0);
}

int update_turn(t_data *data)
{
	data->player.routation_ang += MOVE_SPEED * rad(data->player.turn_dir);
	initializ(data);
	return (0);
}

int initializ(t_data *data)
{
	angle_adjust(&data->player.routation_ang);//foo
	get_dimensions(data);
	draw_win(data);
	mlx_put_image_to_window(data->win.mlx, data->win.mlx_win, data->main_img.img, 0, 0);
    return (0);
}

void create_map(t_data *data)
{
	t_img	img;

	img.img = mlx_new_image(data->win.mlx, WIN_X, WIN_Y);
	data->main_img = img;
	data->main_img.addr = mlx_get_data_addr(data->main_img.img, &data->main_img.bits_per_pixel, &data->main_img.line_length,
								&data->main_img.endian);
	get_player_pos(data);
	initializ(data);
}

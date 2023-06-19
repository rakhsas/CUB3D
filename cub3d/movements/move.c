/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:32:52 by aankote           #+#    #+#             */
/*   Updated: 2023/06/18 13:56:03 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int check_move(t_data *data, int x, int y)
{
    if(data->map->map_copy[(y + MOVE_SPEED) / CARE][(x + MOVE_SPEED) / CARE] == '1')
        return(0);
    if(data->map->map_copy[(y + MOVE_SPEED) / CARE][(x) / CARE] == '1')
        return (0);
    if (data->map->map_copy[(y ) / CARE][(x + MOVE_SPEED) / CARE] == '1')
        return (0);
    return (1);
}

int move_up(t_data *data)
{
    int x;
    int y;
    double cosin;
    double sino;

    cosin = cos(data->player.routation_ang);
    sino = sin(data->player.routation_ang);
    data->player.walk_dir = 1;
    data->player.movestep = data->player.walk_dir * MOVE_SPEED;
	x = data->player.px_pos + cosin * data->player.movestep;
	y = data->player.py_pos + sino * data->player.movestep;
    if(check_move(data, x, y))
        update_walk(data);
    return (0);
}

int move_down(t_data *data)
{
    int x;
    int y;
    double cosin;
    double sino;

    cosin = cos(data->player.routation_ang);
    sino = sin(data->player.routation_ang);
    data->player.walk_dir = -1;
    data->player.movestep = data->player.walk_dir * MOVE_SPEED;
	x = data->player.px_pos + cosin * data->player.movestep;
	y = data->player.py_pos  + sino * data->player.movestep;
    if(check_move(data, x, y))
        update_walk(data);
    return (0);
}

int move_left(t_data *data)
{
    int x;
    int y;
    double cosin;
    double sino;

    cosin = cos(data->player.routation_ang + rad(90));
    sino = sin(data->player.routation_ang + rad(90));
    data->player.walk_dir = -1;
    data->player.movestep = data->player.walk_dir * MOVE_SPEED;
	x = data->player.px_pos + cosin * data->player.movestep ;
	y = data->player.py_pos  + sino  * data->player.movestep;
    if(check_move(data, x, y))
        update_walk_rl(data);
    return (0);
}

int move_right(t_data *data)
{
    int x;
    int y;
    double cosin;
    double sino;

    cosin = cos(data->player.routation_ang + rad(90));
    sino = sin(data->player.routation_ang + rad(90));

    data->player.walk_dir = 1;
    data->player.movestep = data->player.walk_dir * MOVE_SPEED;
	x = data->player.px_pos + cosin * data->player.movestep;
	y = data->player.py_pos  + sino  * data->player.movestep;
    if(check_move(data, x, y))
        update_walk_rl(data);
    return (0);
}

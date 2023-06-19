/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 11:21:39 by aankote           #+#    #+#             */
/*   Updated: 2023/06/18 18:56:57 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int is_player(int c)
{
    if(c == 'E' || c == 'W')
        return (1);
    if(c == 'S' || c == 'N')
        return (1);
    return (0);
}

void draw_ray(t_data *data, double x, double y, int color)
{
    int steps;
    double xinc;
    double yinc;
    int i;

    i = 0;
    steps = fabs(x - ( MAP_X / 2 - P_SIZE / 2));
    if(fabs(y - MAP_Y / 2 - P_SIZE / 2) > fabs(x -  MAP_X / 2 - P_SIZE / 2))
        steps = fabs(y - MAP_Y / 2 - P_SIZE / 2);
    xinc = (x -  MAP_X / 2 - P_SIZE / 2) / steps;
    yinc = (y - MAP_Y / 2 - P_SIZE / 2) / steps;
    x =   MAP_X / 2 + P_SIZE / 2;
    y = MAP_Y / 2 + P_SIZE / 2;
    while(i < steps)
    {
        my_mlx_pixel_put(&data->main_img, (int)x, (int)y, color);
        x += xinc;
        y += yinc;
        i ++;
    }
}

void draw_p_dir(t_data *data)
{
    double x;
    double y;

    x = cos(data->player.routation_ang) * 10 + MAP_X / 2 + P_SIZE / 2;
    y = sin(data->player.routation_ang) * 10 + MAP_Y / 2 + P_SIZE / 2;
    draw_ray(data, x, y, GREEN);
}



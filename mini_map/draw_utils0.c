/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 11:21:39 by aankote           #+#    #+#             */
/*   Updated: 2023/06/15 11:12:17 by rakhsas          ###   ########.fr       */
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
int draw_squart(t_data *data ,int x, int y)
{
    int x0;
    int y0;

    y0 = y;
    while(y < y0 + CARE)
    {
        x0 = x;
        while(x0 < x + CARE)
        {
            if(data->map->map_copy[y / CARE][x / CARE] == '1')
                my_mlx_pixel_put(&data->main_img, x0 ++, y, WALL);
            else if(data->map->map_copy[y / CARE][x / CARE] == '0' || is_player(data->map->map_copy[y / CARE][x / CARE]))
                my_mlx_pixel_put(&data->main_img, x0 ++, y, WAY);
            else
                x0 ++;
        }
        y ++;
    }
    return (0);
}

int draw_lines(t_data *data)
{
    int x;
    int y;

    y = 0;
    while(y < data->win.map_y )
    {
        x = 0;
        while (x < data->win.map_x)
        {
            if(x % CARE == 0 || y % CARE == 0)
                my_mlx_pixel_put(&data->main_img, x, y, LINE);
            x ++;
        }
        y ++;
    }
    return (0);
}

int draw_player(t_data *data, int x_pos, int y_pos)
{
    int x;
    int y;

    y = y_pos;
    while(y < y_pos + P_SIZE)
    {
        x = x_pos;
        while(x < x_pos + P_SIZE)
             my_mlx_pixel_put(&data->main_img, x++, y, PLAYER);
        y ++;
    }
    return (0);
}

int draw_map(t_data *data)
{
    int x;
    int y;

    x = 0;
    y = 0;
	// get_dimensions(data);
    while(y < data->win.map_y)
    {
        x = 0;
        while(x < data->win.map_x)
        {
            draw_squart(data, x , y);
            x += CARE;
        }
        y += CARE;
    }
    return (0);
}

// int draw_map(t_data *data)
// {
//     int x;
//     int y;

//     x = 0;
//     y = 0;
// 	get_dimensions(data);
//     while(y < data->win.map_y)
//     {
//         x = 0;
//         while(x < data->win.map_x)
//         {
//             draw_squart(data, x , y);
//             x += CARE;
//         }
//         y += CARE;
//     }
//     return (0);
// }
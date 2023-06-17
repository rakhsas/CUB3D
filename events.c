/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:48:48 by aankote           #+#    #+#             */
/*   Updated: 2023/06/15 15:56:11 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_exit(void *key)
{
	(void)key;
    printf("Exit\n");
	exit(0);
}

int ft_key_hook(int key, t_data *data)
{
    if(key == 53)
    {
        printf("Exit\n");
        exit (0);
    }
    if(key == 126 || key == 13)
    {
        // printf("Up\n");
        move_up(data);
    }
    if(key == 1 || key == 125)
    {
        move_down(data);
        // printf("down\n");
    }
    if(key == 2)
    {
        // printf("Right\n");
        move_right(data);
    }
    if(key == 0)
    {
        move_left(data);
        // printf("Left\n");
    }
    if(key == 123)
    {
        data->player.turn_dir = -1;
        update_turn(data);
    }
    if(key == 124)
    {
       data->player.turn_dir = +1;
       update_turn(data);
    }
    return (0);
}

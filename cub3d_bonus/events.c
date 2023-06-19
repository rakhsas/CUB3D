/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:48:48 by aankote           #+#    #+#             */
/*   Updated: 2023/06/19 11:43:03 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_exit(void *key)
{
	(void)key;
	printf("Exit\n");
	exit(0);
}

int	ft_key_hook(int key, t_data *data)
{
	if (key == 53)
		exit (0);
	if (key == 126 || key == 13)
		move_up(data);
	if (key == 1 || key == 125)
		move_down(data);
	if (key == 2)
		move_right(data);
	if (key == 0)
		move_left(data);
	if (key == 123)
	{
		data->player.turn_dir = -1;
		update_turn(data);
	}
	if (key == 124)
	{
		data->player.turn_dir = +1;
		update_turn(data);
	}
	return (0);
}

int	ft_mouse(int button, int x, int y, t_data *data)
{
	x = 0;
	y = 0;
	if (button == 1)
	{
		data->player.turn_dir = -1;
		update_turn(data);
	}
	else if (button == 2)
	{
		data->player.turn_dir = +1;
		update_turn(data);
	}
	else if (button == 4)
	{
		data->player.walk_dir = -1;
		move_down(data);
	}
	else if (button == 5)
	{
		data->player.walk_dir = +1;
		move_up(data);
	}
	return (0);
}

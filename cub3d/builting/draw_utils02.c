/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 10:47:28 by aankote           #+#    #+#             */
/*   Updated: 2023/06/18 21:17:12 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void    angle_adjust(double *ray_angle)
{
    *ray_angle = fmod(*ray_angle , (2 * PI));
    if(*ray_angle < 0)
        *ray_angle = (2 * PI) + *ray_angle;
    if(*ray_angle >= rad(360))
        *ray_angle = 0;
}

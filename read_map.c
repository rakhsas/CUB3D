/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:33:07 by aankote           #+#    #+#             */
/*   Updated: 2023/06/12 11:04:25 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_join(char *r_buff, char *buff)
{
	char	*temp;

	temp = ft_strjoin(r_buff, buff);
	free(r_buff);
	return (temp);
}

// void	ft_error(char *msg)
// {
// 	ft_putstr_fd(msg, 1);
// 	exit(1);
// }

char	*read_map(int fd)
{
	char	*buff;
	char	*res;

	res = ft_calloc(1, 1);
	while (1)
	{
		buff = get_next_line(fd);
		if (!buff)
			break ;
		if (ft_strlen(buff) <= 1)
			ft_error("ERROR!\nEmpty line in map.\n", "");
		res = ft_join(res, buff);
		free(buff);
	}
	return (res);
}

char	**split_map(int fd)
{
	char	**p;
    char *map;

    map = read_map(fd);
	if (!map)
		return (0);
	p = ft_split(map, '\n');
	return (p);
}

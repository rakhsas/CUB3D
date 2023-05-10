/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:12:20 by rakhsas           #+#    #+#             */
/*   Updated: 2022/10/30 13:24:50 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	index;
	int	len;

	index = 0;
	len = ft_strlen(s);
	while (index < len)
	{
		ft_putchar_fd(index[s], fd);
		index++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:04:41 by rakhsas           #+#    #+#             */
/*   Updated: 2023/05/04 16:45:15 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

// size_t	ft_strlen(char *str);

int		check_newline1(char *str);

char	*get_next_line(int fd);
char	*free_it(char *str);
char	*free_line(char *str);
char	*str_join(char const	*str, char const	*rts);
char	*get_l(char *save);
char	*save(char *save);

void	*ft_memmove(void *dst, const void *src, size_t len);

#endif
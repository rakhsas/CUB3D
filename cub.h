/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:14:34 by rakhsas           #+#    #+#             */
/*   Updated: 2023/05/22 10:25:26 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "stdlib.h"
# include "stdio.h"
# include "unistd.h"
# include "string.h"
# include "fcntl.h"
# include "mlx.h"
# include "math.h"
# include "stdbool.h"

typedef struct s_player
{
	int		p_posx;
	int		p_posy;
	char	p_dir;
}	t_player;

typedef struct s_textures
{
	int				no;
	int				so;
	int				ea;
	int				we;
}	t_textures;
typedef struct s_map
{
	char			**map;
	char			**map_copy;
	char			**c_tab;
	int				len_vert;
	int				len_hori;
	int				c_p[3];
	int				f_p[3];
	int				height;
	char			*no;
	char			*so;
	char			*ea;
	char			*we;
	char			*f;
	char			*c;
	t_player		*player;
	t_textures		*textures;
}	t_map;

int		check_for_chars(char *line);
int		check_extension(char *str);
void	initialize(t_map *s_map);
void	parse(char **map);
char	**fill_map(int fd);
char	*join_free(char *s1, char *s2);
void	get_infos_from_map(t_map *s_map);
void	skip_spaces(char *str);
void	get_specified_data(t_map *s_map);
void	skip_useless_data(t_map *s_map);
char	*ma3rftch(char *str, char c);
char	*ft_strtrim_free(char *str, char *rts);
int		bubble_sort(char **s1);
void	parse_first_part(t_map *s_map, int fd);
void	check_for_textures_extension(t_map *s_map);
void	check_for_textures_path(t_map *s_map);
char	*test(char *str);
void	check_for_max_255(char	*str, int *c_p);
void	check_border_top(t_map *s_map);
void	check_border_bottom(t_map *s_map);
void	check_border_left(t_map *s_map);
void	check_border_right(t_map *s_map);
void	check_path(t_map *s_map, int i, int j);
void	make_the_map_rectangle(t_map *s_map, int max);
void	check_if_spaces(t_map *s_map);
int		ft_check_right_top(t_map *s_map, int i, int j, int flag);
int		ft_check_left_bottom(t_map *s_map, int i, int j, int flag);
int		get_max_len(t_map *s_map);
void	check_for_unwanted_chars(t_map *s_map);
void	make_the_map_rectangle(t_map *s_map, int max);
void	get_map(t_map *s_map);
void	initialize_sec_part(t_map *s_map);
#endif
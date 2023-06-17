# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 10:42:23 by aankote           #+#    #+#              #
#    Updated: 2023/06/16 16:51:01 by rakhsas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

FILES = cub3d.c events.c movements/move.c \
		read_map.c mini_map/draw.c mini_map/draw_utils0.c mini_map/draw_utils01.c mini_map/draw_utils02.c \
		mini_map/check_hor.c mini_map/check_ver.c mini_map/check_intersictions.c window/main_window.c \
		parse/parse.c parse/extensions.c parse/checks.c parse/textures.c parse/checks1.c\
		parse/vulnerabilities.c mini_map/textures.c

OBJCS = $(FILES:.c=.o)

INCLUDES = get_next_line/get_next_line.a libft/libft.a
FRAMEWORK = -lmlx -framework OpenGL -framework AppKit -static-libsan

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

CC = cc

all : $(NAME)

$(NAME) : $(OBJCS)
	@echo "\n"
	@make -C libft
	@make -C get_next_line
	@echo "\033[0;32mCompiling cub3D..."
	@$(CC) $(CFLAGS) $(INCLUDES) $(FRAMEWORK) $(OBJCS) -o $(NAME) $(INCLUDES)


clean :
	@echo "\033[0;31mCleaning libft..."
	@make clean -C libft/
	@make clean -C get_next_line/
	@echo "\nRemoving binaries..."
	rm -fr $(OBJCS)

fclean : clean
	@make fclean -C libft/
	@make fclean -C get_next_line/
	@echo "\nDeleting objects..."
	@echo "\nDeleting executable..."
	rm -fr $(NAME)

re : fclean all

run : all clean

push : fclean
	git add .
	git commit -m "UPDATED"
	git push

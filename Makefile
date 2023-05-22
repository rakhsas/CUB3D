NAME = cub3d

CC = cc
BLT = builtins
PRC = parcing
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
FILES = main.c src/parse/parse.c src/parse/extensions.c src/parse/checks.c src/parse/textures.c src/parse/checks1.c\
		src/parse/vulnerabilities.c
LIBFT = ./libft/libft.a
GETNEXTLINE = ./get_next_line/get_next_line.a
MFLAGS = -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGl -framework AppKit
OBJCS = $(FILES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJCS)
	@echo "\n"
	@make -C libft
	@make -C get_next_line
	@echo "\033[0;32mCompiling CUB3D..."
	@$(CC)  $(OBJCS) $(CFLAGS) $(MFLAGS) $(LIBFT) $(GETNEXTLINE) -o $(NAME)
	@echo "\n\x1b[34mDone !\033[0m"

%.o:%.c
	@printf "\033[0;33mGenerating CUB3D objects... %-33.33s\r" $@
	@$(CC)  $(CFLAGS)  -c $<  -o $@

clean :
	@echo "\033[0;31mCleaning libft..."
	@make clean -C libft/
	@make clean -C get_next_line/
	@echo "\nRemoving binaries..."
	rm -fr $(OBJCS)
	@echo "\033[0;31m𝑶𝒃𝒋𝒆𝒄𝒕𝒔' 𝒄𝒍𝒆𝒂𝒏𝒆𝒅\033[0m"
	@echo "\033[0m"

fclean : clean
	@echo "\033[0;31mCleaning libft..."
	@make fclean -C libft/
	@make fclean -C get_next_line/
	@echo "\nDeleting objects..."
	@echo "\nDeleting executable..."
	@rm -f $(NAME)
	@echo "\033[0m"

re :fclean all

run : re clean
	clear
	@./cub3d


push : fclean
	git add .
	git commit -m "Updated"
	git push
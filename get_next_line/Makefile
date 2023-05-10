NAME = get_next_line.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
ARC = ar rc
FILES = get_next_line.c get_next_line_utils.c

OBJCS = $(FILES:.c=.o)
OBJCS_B = $(FILES_B:.c=.o)
all : $(NAME)

$(NAME) : $(OBJCS)
	@echo "\n\n\033[0;32mCompiling get_next_line..."
	@$(ARC) $(NAME) $(OBJCS)
	@echo "\033[0m"

%.o : %.c
	@printf "\033[0;33mGenerating get_next_line objects... %-33.33s\r" $@
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -fr $(OBJCS)
fclean : clean
	@rm -fr $(NAME)
re :fclean all
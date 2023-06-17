NAME = get_next_line.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
ARC = ar rc
FILES = get_next_line.c get_next_line_utils.c

OBJCS = $(FILES:.c=.o)
OBJCS_B = $(FILES_B:.c=.o)
all : $(NAME)

$(NAME) : $(OBJCS) 
	@$(ARC) $(NAME) $(OBJCS)


bonus :$(OBJCS_B)
	@$(ARC) $(NAME) $(OBJCS_B)


%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[0;32m𝘾𝙧𝙚𝙖𝙩𝙞𝙣𝙜 ...\033[0m"
clean :
	@rm -fr $(OBJCS)
	@rm -fr $(OBJCS_B)
fclean : clean
	@rm -fr $(NAME)
re :fclean all
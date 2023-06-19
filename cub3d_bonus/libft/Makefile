NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
ARC = ar rc
FILES = ft_isdigit.c ft_memset.c ft_strjoin.c ft_strtrim.c ft_isprint.c\
		ft_strlcat.c ft_atoi.c ft_substr.c ft_putchar_fd.c\
		ft_strlcpy.c ft_tolower.c ft_bzero.c  ft_strlen.c ft_putstr_fd.c\
		ft_toupper.c ft_calloc.c ft_memchr.c ft_isalnum.c ft_striteri.c ft_putendl_fd.c\
		ft_memcmp.c ft_split.c ft_strncmp.c ft_putnbr_fd.c ft_isalpha.c ft_memcpy.c ft_strchr.c\
		ft_strnstr.c ft_isascii.c ft_memmove.c ft_strdup.c ft_strrchr.c ft_itoa.c ft_strmapi.c \
		str_tolower.c my_atoi.c ft_error.c my_join.c

OBJCS = $(FILES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJCS)
	@echo "\n\n\033[0;32mCompiling libft..."
	@$(ARC) $(NAME) $(OBJCS)
	@echo "\033[0m"

%.o : %.c
	@printf "\033[0;33mGenerating libft objects... %-33.33s\r" $@
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -fr $(OBJCS)

fclean : clean
	@rm -fr $(NAME)

re :fclean all
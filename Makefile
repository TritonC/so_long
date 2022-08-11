NAME = so_long
SRC = testing.c hooks.c
CFLAGS = -Wall -Wextra -Werror -Imlx
RM = /bin/rm -rf
CC = gcc
OBJ = $(SRC:.c=.o)
$(NAME): $(OBJ)
#$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
	gcc  $(CFLAGS) libft/libft.a $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)
clean: 
	$(RM) $(OBJ)
fclean: clean 
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re
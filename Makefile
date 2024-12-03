CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC) -g3 -fsanitize=address
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

INC = so_long.h

SRC = ft_split.c ft_itoa.c ft_strtrim.c get_next_line.c get_next_line_utils.c main.c mlx.c mlx1.c mlx2.c mlx3.c validation.c validation_1.c validation_2.c validation_3.c
OBJ = $(SRC:.c=.o)

NAME = so_long

.PHONY = NAME, all, clean, fclean, re

all: $(NAME)

$(NAME) : $(OBJ) Makefile so_long.h
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJ) -o $(NAME)

%.o : %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
		rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)

re : fclean all
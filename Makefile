CC = cc
CFLAGS = -Wall -Wextra ##-fsanitize=address

SRC = load_map.c flood_fill.c ft_mlx_imag.c Functions_are_not_included.c get_next_line.c get_next_line_utils.c

OBJ = $(SRC:%.c=%.o)

NAME = so_long
HFILE = so_long.h

all: $(NAME)

$(NAME): main.c $(OBJ)
	$(CC) $(CFLAGS) $^ -L/home/ylagzoul/Desktop/include/mlx/ -lmlx -lX11 -lXext -o $@

%.o: %.c $(HFILE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: clean
NAME = bsq

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
	read_file.c \
	parse_header.c \
	validate_map.c \
	solve_bsq.c \
	draw_square.c \
	utils.c \
	output.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

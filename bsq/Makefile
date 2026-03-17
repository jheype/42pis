NAME = bsq

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
	read_file.c \
	parse_header.c \
	validate_map.c \
	solve_bsq.c \
	print_map.c \
	utils.c \
	output.c \
	bsq.h \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

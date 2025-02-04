CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = .
LIBFT_DIR = libft
INCLUDES = -I $(LIBFT_DIR)
LDFLAGS = -L $(LIBFT_DIR) -lft -lXext -lX11 -lm


SRC = $(wildcard $(SRC_DIR)/*.c)

OBJ = $(SRC:.c=.o)

NAME = push_swap

LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(SRC_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

run: $(NAME)
	./$(NAME)

.PHONY: all clean fclean re run

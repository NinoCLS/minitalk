SRC_1 = src/client.c
OBJ_1 = $(SRC_1:.c=.o)

SRC_2 = src/server.c
OBJ_2 = $(SRC_2:.c=.o)

SRC_3 = src/client_bonus.c
OBJ_3 = $(SRC_3:.c=.o)

SRC_4 = src/server_bonus.c
OBJ_4 = $(SRC_4:.c=.o)

CFLAGS = -Wall -Werror -Wextra
LIBFT_PATH = libft

NAME_CLIENT = client
NAME_SERVER = server
NAME_CLIENT_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus

$(NAME_CLIENT): $(NAME_SERVER) $(OBJ_1) libft 
	$(MAKE) -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJ_1) -L$(LIBFT_PATH) -lft -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_2) libft
	$(MAKE) -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJ_2) -L$(LIBFT_PATH) -lft -o $(NAME_SERVER)

$(NAME_CLIENT_BONUS): $(OBJ_3) libft 
	$(MAKE) -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJ_3) -L$(LIBFT_PATH) -lft -o $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS): $(OBJ_4) libft
	$(MAKE) -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJ_4) -L$(LIBFT_PATH) -lft -o $(NAME_SERVER_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	$(MAKE) -C $(LIBFT_PATH)

all: $(NAME_CLIENT) $(NAME_SERVER)

bonus: $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

clean:
	rm -f $(OBJ_1) $(OBJ_2) $(OBJ_3) $(OBJ_4)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
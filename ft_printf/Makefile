NAME = libftprintf.a
LIBFT_NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src/
INC_DIR = include/
LIB_DIR = libft
SRCS = $(SRC_DIR)ft_print_hex.c $(SRC_DIR)ft_print_ptr.c $(SRC_DIR)ft_print_unsigned_nb.c \
		$(SRC_DIR)ft_printf_helpers.c $(SRC_DIR)ft_printf.c
INCS = $(INC_DIR)ft_printf.h
OBJS = $(SRCS:.c=.o)
AR = ar rc

all: $(NAME)

$(NAME): makelibft $(OBJS)
	$(AR) $(NAME) $(OBJS)

makelibft:
	$(MAKE) -C $(LIB_DIR)
	@cp $(LIB_DIR)/$(LIBFT_NAME) .
	@mv $(LIBFT_NAME) $(NAME) 

clean:
	$(MAKE) -C $(LIB_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIB_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

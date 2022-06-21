NAME = libftprintf.a
HEADERS_DIRS = includes $(LIBFT_DIR)
HEADERS = includes/ft_printf.h $(LIBFT_DIR)/libft.h
CC = gcc
C_FLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIB = ft
SRC_DIR = srcs
OBJ_DIR = obj
SRCS = ft_printf	\
       ft_printf_utils	\
       print_c	\
       print_s	\
       print_d	\
       print_p	\
       print_u	\
       print_x
OBJ_FILE = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRCS)))
SRC_FILE = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRCS)))

all: check_libft $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ_FILE)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ_FILE)

bonus: $(NAME)

check_libft:
	$(MAKE) -C $(LIBFT_DIR)

$(LIBFT): check_libft

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) -c $(C_FLAGS) $(foreach h, $(HEADERS_DIRS), -I$h) $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all, clean, fclean, re, check_libft

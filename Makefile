# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/07 04:49:11 by amyburgh          #+#    #+#              #
#    Updated: 2018/09/10 22:15:15 by amyburgh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc
CFLAFGS = -Wall -Werror -Wextra -pthread
FRAMEWORKS = -framework OpenGL -framework Appkit
DUBUG = -fsanitize=address

SRCDIR = ./src
OBJDIR = ./obj
INCDIR = ./include

LIBFT = ./libft
MLX = ./minilibx

SRC_FILES = main.c \
			init.c \
			image.c \
			mouse_hooks.c \
			key_hooks.c \
			render.c \
			mj_fractals.c \
			br_fractals.c \
			td_fractals.c \
			colors.c \
			smooth_colors.c \

SRC = $(addprefix $(SRCDIR)/, $(SRC_FILES))
OBJ = $(addprefix $(OBJDIR)/, $(SRC_FILES:.c=.o))
INC = $(addprefix -I, $(INCDIR))

.PHONY: all clean fclean re
.SILENT:

all: build $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	make -C $(MLX)
	$(CC) $(CFLAGS) -L $(LIBFT) -lft -L $(MLX) -lmlx $(FRAMEWORKS) -Ofast -o $@ $^
	echo "executable: \033[32m[CREATED]\033[0m"

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CLFAGS) $(INC) -I $(LIBFT)/include -I $(MLX) -Ofast -o $@ -c $<

build:
	mkdir -p $(OBJDIR)

clean:
	make clean -C $(LIBFT)
	make clean -C $(MLX)
	rm -rf $(OBJDIR)

fclean:	clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)
	echo "executable: \033[32m[REMOVED]\033[0m"

re:	fclean all

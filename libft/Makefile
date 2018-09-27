# **************************************************************************** #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/19 14:04:37 by amyburgh          #+#    #+#              #
#    Updated: 2018/05/09 17:21:16 by amyburgh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -O

SRCDIR = ./src
OBJDIR = ./obj
INCDIR = ./include

# INC_FILES =	macros.h	libft.h	get_next_line.h
	  
SRC_FILES = ft_memset.c		ft_bzero.c		ft_memcpy.c		ft_memccpy.c	ft_memmove.c\
			ft_memchr.c		ft_memcmp.c		ft_strlen.c		ft_strdup.c		ft_strcpy.c\
			ft_strncpy.c	ft_strcat.c		ft_strncat.c	ft_strlcat.c	ft_strchr.c\
			ft_strrchr.c	ft_strstr.c		ft_strnstr.c	ft_strcmp.c		ft_strncmp.c\
			ft_atoi.c		ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	ft_isascii.c\
			ft_isprint.c	ft_toupper.c	ft_tolower.c\
			ft_memalloc.c	ft_memdel.c		ft_strnew.c		ft_strdel.c		ft_strclr.c\
			ft_striter.c	ft_striteri.c	ft_strmap.c		ft_strmapi.c	ft_strequ.c\
			ft_strnequ.c	ft_strsub.c		ft_strjoin.c	ft_strtrim.c	ft_putchar.c\
			ft_putstr.c		ft_putendl.c	ft_putnbr.c		ft_putchar_fd.c	ft_putstr_fd.c\
			ft_putendl_fd.c	ft_putnbr_fd.c	ft_itoa.c		ft_strsplit.c	ft_strccpy.c\
			ft_lstnew.c		ft_lstdelone.c	ft_lstdel.c		ft_lstadd.c		ft_lstaddend.c\
			ft_lstiter.c	ft_lstmap.c\
			ft_wordcount.c	ft_digitcount.c	ft_swap.c		ft_strrev.c		ft_strndup.c\
			ft_strnjoin.c	get_next_line.c	ft_strcasecmp.c

SRC = $(addprefix $(SRCDIR)/, $(SRC_FILES))
OBJ = $(addprefix $(OBJDIR)/, $(SRC_FILES:.c=.o))
INC = $(addprefix -I, $(INCDIR))

.PHONY: all clean fclean re
.SILENT:

all: build $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $@
	echo "libft.a: \033[32m[CREATED]\033[0m"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

build:
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)
	echo "object_files: \033[32m[REMOVED]\033[0m"

fclean:	clean
	rm -f $(NAME)
	echo "libft.a: \033[32m[REMOVED]\033[0m"

re:	fclean all

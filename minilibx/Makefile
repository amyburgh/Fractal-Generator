#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

.SILENT:

all: $(NOM)

$(NOM):	$(OBJ)
	ar -r $(NOM) $(OBJ)
	ranlib $(NOM)
	echo "libmlx.a: \033[32m[CREATED]\033[0m"

clean:
	rm -f $(NOM) $(OBJ) *~
	rm -f mlx_app
	echo "libmlx.a: \033[32m[REMOVED]\033[0m"

re: clean all

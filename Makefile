CC = gcc

NAME = so_long

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -static-libsan -g

LIBFT = libft

HEADER = includes

SRCS =	src/so_long.c \
		src/error_delete.c \
		src/map.c \
		src/map_check.c \
		src/init.c \
		src/get_picture.c \
		src/map_parse.c \
		src/mlx_pixels.c \
		src/hooks.c \
		src/collect.c \
		src/move.c \
		src/free.c
OBJS =	src/so_long.o \
		src/error_delete.o \
		src/map.o \
		src/map_check.o \
		src/init.o \
		src/get_picture.o \
		src/map_parse.o \
		src/mlx_pixels.o \
		src/hooks.o \
		src/collect.o \
		src/move.o \
		src/free.o

all: $(NAME) $(LIBFT)

$(NAME): $(OBJS)
	@echo "\033[37;1;41m [ .. ] | Compiling libft.. \033[0m"
	@make -C $(LIBFT)
	@echo " [\033[32m OK \033[0m] | libft ready!"
	@echo "\033[37;1;41m [ .. ] | Compiling minilibx.. \033[0m"
	@make -C mlx
	@echo " [\033[32m OK \033[0m] | minilibx ready!"
	@cp mlx/libmlx.dylib ./
	@echo "\033[37;1;41m [ .. ] | Compiling so_long.. \033[0m"
	@$(CC) $(CFLAGS) $(SRCS) -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -lz -o $(NAME)
	@echo " [\033[32m OK \033[0m] | ready to play!"
clean:
	@rm -f $(OBJS) libmlx.dylib
	@make clean -C $(LIBFT)
	@make clean -C mlx
	@echo "\033[37;1;41m object files removed. \033[0m" 
fclean: clean
	@rm -f $(NAME) libmlx.dylib
	@make fclean -C $(LIBFT)
	@make clean -C mlx
	@echo "\033[37;1;41m binary file removed. \033[0m"
re: fclean all

.PHONY: fclean re all clean

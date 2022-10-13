NAME = fdf

CCFLAGS = -Wall -Wextra -Werror

PATH_INCS = .
PATH_SRCS = .
PATH_OBJS = .
LIBDIR = libft
LIB = $(LIBDIR)/libft.a
MLX = minilibx-linux/libmlx.a 

SRCS = $(addprefix $(PATH_SRCS)/, fdf.c)

OBJS = $(SRCS:$(PATH_SRCS)/%.c=$(PATH_OBJS)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(OBJS): $(SRCS)
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

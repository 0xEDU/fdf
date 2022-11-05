NAME = fdf

CCFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -lXext -lX11 -lm

PATH_INCS = .
PATH_SRCS = .
PATH_OBJS = .

LIBDIR = libft
LIB = $(LIBDIR)/libft.a

SRCS = $(addprefix $(PATH_SRCS)/, main.c \
	   map_draw_alg.c         \
	   map_generation.c       \
	   map_line_parsing.c     \
	   map_metadata.c         \
	   map_move.c             \
	   map_render.c           \
	   map_transformations.c  \
	   map_zoom.c             \
	   mlx_draw_utils.c       \
	   mlx_events.c           \
	   mlx_window.c)

OBJS = $(SRCS:$(PATH_SRCS)/%.c=$(PATH_OBJS)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make --no-print-directory -C $(LIBDIR)
	@make --no-print-directory -C $(LIBDIR) clean
	@$(CC) $(CCFLAGS) $(OBJS) $(LIB) $(MLXFLAGS) -o $(NAME)
	@echo -e "\033[32m[FdF created]\033[0m"

$(OBJS): $(SRCS)
	@$(CC) $(CCFLAGS) -c $(SRCS)
	@echo -e "\033[32m[FdF objects created]\033[0m"

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

NAME = fdf

CCFLAGS = -Wall -Wextra -Werror -g3
MLXFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -O3

PATH_INCS = .
PATH_SRCS = .
PATH_OBJS = .

LIBDIR = libft
LIB = $(LIBDIR)/libft.a

SRCS = $(addprefix $(PATH_SRCS)/, fdf.c \
	   bresenham.c       \
	   events.c          \
	   map_render.c      \
	   map_generation.c  \
	   map_utils.c       \
	   move.c            \
	   mlx_utils_1.c     \
	   transformations.c \
	   fdf_utils.c       \
	   zoom.c)

OBJS = $(SRCS:$(PATH_SRCS)/%.c=$(PATH_OBJS)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make --no-print-directory -C $(LIBDIR)
	@make --no-print-directory -C $(LIBDIR) clean
	@$(CC) $(CCFLAGS) $(OBJS) $(LIB) $(MLXFLAGS) -o $(NAME)
	@echo -e "\033[32m[FdF created]\033[0m"

$(OBJS): $(SRCS)
	@$(CC) $(CCFLAGS) -c $(SRCS) -Iminilibx-linux
	@echo -e "\033[32m[FdF objects created]\033[0m"

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

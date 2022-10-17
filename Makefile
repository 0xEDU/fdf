NAME = fdf

CCFLAGS = -Wall -Wextra -Werror -g3
MLXFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz

PATH_INCS = .
PATH_SRCS = .
PATH_OBJS = .

LIBDIR = libft
LIB = $(LIBDIR)/libft.a

SRCS = $(addprefix $(PATH_SRCS)/, fdf.c \
	   mlx_utils.c)

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

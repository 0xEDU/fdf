NAME = fdf

CCFLAGS = -Wall -Wextra -Werror

PATH_INCS = .
PATH_SRCS = .
PATH_OBJS = .
LIBDIR = libft
LIB = $(LIBDIR)/libft.a

SRCS = $(addprefix $(PATH_SRCS)/, fdf.c)

OBJS = $(SRCS:$(PATH_SRCS)/%.c=$(PATH_OBJS)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBDIR)
	$(CC) $(CCFLAGS) -o $(NAME) $(OBJS) $(LIB) -lm

$(OBJS): $(SRCS)
	$(CC) $(CCFLAGS) -c $(SRCS) -I $(PATH_INCS)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

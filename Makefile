# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etachott <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 19:01:25 by etachott          #+#    #+#              #
#    Updated: 2022/10/11 19:12:26 by etachott         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CCFLAGS = -Wall -Wextra -Werror

PATH_INCS = .
PATH_SRCS = .
PATH_OBJS = .
LIBDIR = libft
LIB = $(LIBDIR)/libft.a

LXFLAGS = -lXext -lX11 -lm

SRCS = $(addprefix $(PATH_SRCS)/, fdf.c)

OBJS = $(SRCS:$(PATH_SRCS)/%.c=$(PATH_OBJS)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBDIR)
	clang $(CCFLAGS) -o $(NAME) $(OBJS) $(LIB) $(LXFLAGS)

$(OBJS): $(SRCS)
	clang $(CCFLAGS) -c $(NAME) -I $(PATH_INCS) -I minilibx-linux/ -L minilibx-linux/ $(LXFLAGS) -lmlx_Linux

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

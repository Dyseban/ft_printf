# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/03 14:34:05 by thgermai          #+#    #+#              #
#    Updated: 2020/01/03 16:53:19 by thgermai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = 	./srcs/ft_printf.c\
		./srcs/pf_arg.c\
		./srcs/pf_fill_1_5.c\
		./srcs/pf_fill_6_9.c\
		./srcs/pf_parsing.c\
		./srcs/pf_width.c\
		./srcs/pf_precision.c
OBJS = $(SRCS:.c=.o)
LIB_OBJS = ./libft/*.o
INCLUDES = ./includes/ft_printf.h
LIB = ./libft/libft.a
CFLAGS = -Wall -Wextra -Werror -g3
LOGFILE=$(LOGPATH) `date +'%y.%m.%d %H:%M:%S'`

all : $(NAME)

.c.o : $(SRCS)
	@(gcc -c $(CFLAGS) -I $(INCLUDES) $^ -o $(^:.c=.o))

$(NAME) : $(OBJS)
	@(make -C libft)
	@(ar rcs $(NAME) $(OBJS) $(LIB_OBJS))
	@(echo "ft_printf compiled")

ex : $(NAME)
	@(gcc $(CFLAGS) $(NAME) srcs/main.c -I $(INCLUDES))
	@(./a.out)

clean :
	@(rm -f $(OBJS))
	@(make clean -C libft)
	@(echo "ft_printf cleaned")

cleanlib :
	@(make fclean -C libft)

fclean : cleanlib clean
	@(rm -rf $(NAME))
	@(rm -f libft.a)
	@(rm -rf a.out.dSYM)
	@(rm -f a.out)
	@(echo "ft_printf full cleaned")

git : fclean
	git add *
	git commit -m "$(LOGFILE)"
	git push

re : fclean all

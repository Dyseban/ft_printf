# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/03 14:34:05 by thgermai          #+#    #+#              #
#    Updated: 2019/12/14 09:56:08 by thgermai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = 	./srcs/ft_printf.c\
		./srcs/pf_arg.c\
		./srcs/pf_fill_1_5.c\
		./srcs/pf_fill_6_9.c\
		./srcs/pf_parcing.c\
		./srcs/pf_width.c\
		./srcs/pf_precision.c
OBJS = $(SRCS:.c=.o)
INCLUDES = ./includes/ft_printf.h\
			#./libft/libft.h
LIB = ./libft/libft.a
CFLAGS = -Wall -Wextra -Werror -g3
LOGFILE=$(LOGPATH) `date +'%y.%m.%d %H:%M:%S'`

all : $(NAME)

.c.o : $(SRCS)
	gcc -c $(CFLAGS) -I $(INCLUDES) $^ -o $(^:.c=.o)

$(NAME) : $(OBJS)
	@(make -C libft)
	ar rcs $(NAME) $(OBJS)

ex : $(NAME)
	@(gcc $(CFLAGS) $(LIB) $(NAME) srcs/main.c -I $(INCLUDES))
	@(./a.out)

f :
	@(make -C libft)
	@(gcc -g3 -fsanitize=address $(LIB) $(SRCS) -I $(INCLUDES))
	@(./a.out)

clean :
	rm -f $(OBJS)
	rm -f a.out

cleanlib :
	make fclean -C libft

fclean : cleanlib clean
	rm -rf $(NAME)
	rm -f libft.a
	rm -rf a.out.dSYM

git : fclean
	git add *
	git commit -m "$(LOGFILE)"
	git push

re : fclean all

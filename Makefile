# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/03 14:34:05 by thgermai          #+#    #+#              #
#    Updated: 2019/12/04 14:36:23 by thgermai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf
SRCS = ./srcs/main.c\
		./srcs/ft_printf.c\
		./srcs/pf_arg.c\
		./srcs/pf_fill_1-5.c\
		./srcs/pf_fill_6-9.c\
		./srcs/pf_parcing.c\
		./srcs/pf_width.c
INCLUDES = ./includes/ft_printf.h\
			./libft/libft.h
LIB = ./libft/libft.a
CFLAGS = -Wall -Wextra -Werror -g3

all : $(NAME)

$(NAME) :
	make -C libft
	gcc $(LIB) $(SRCS) -I $(INCLUDES)
	./a.out

f :
	make -C libft
	gcc -g3 -fsanitize=address $(LIB) $(SRCS) -I $(INCLUDES)
	./a.out

clean :

fclean : clean
	rm -f a.out
	rm -rf a.out.dSYM

re : fclean all

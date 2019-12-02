# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/03 14:34:05 by thgermai          #+#    #+#              #
#    Updated: 2019/12/02 11:15:09 by thgermai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf
SRCS = ./srcs/main.c\
		./srcs/ft_printf.c\
		./srcs/pf_arg.c\
		./srcs/pf_fill_1-5.c\
		./srcs/pf_fill_6-9.c
INCLUDES = ./includes/ft_printf.h\
			./libft/libft.h
LIB = ./libft.a
CFLAGS = -Wall -Wextra -Werror -g3

all : $(NAME)

$(NAME) :
	gcc $(LIB) $(SRCS) -I $(INCLUDES)
	./a.out

f :
	gcc -g3 -fsanitize=address $(LIB) $(SRCS) -I $(INCLUDES)
	./a.out

clean :

fclean : clean
	rm -f a.out
	rm -rf a.out.dSYM

re : fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thomasgermain <thomasgermain@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/03 14:34:05 by thgermai          #+#    #+#              #
#    Updated: 2019/11/28 10:01:59 by thomasgerma      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf
SRCS = ./srcs/main.c\
		./srcs/ft_printf.c\
		./srcs/pf_arg.c
INCLUDES = ./includes/ft_printf.h\
			./libft/libft.h
LIB = ./libft.a
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	gcc $(LIB) $(SRCS) -I $(INCLUDES)
	./a.out

f :
	gcc -g3 -fsanitize=address $(LIB) $(SRCS) -I $(INCLUDES)
	./a.out

clean :

fclean : clean
	rm -f $(NAME)
	rm -rf a.out.dSYM

re : fclean all

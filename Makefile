# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thomasgermain <thomasgermain@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/03 14:34:05 by thgermai          #+#    #+#              #
#    Updated: 2019/11/26 19:54:29 by thomasgerma      ###   ########.fr        #
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

$(NAME) : $(OBJS)
	gcc $(LIB) $(SRCS) -I $(INCLUDES)

clean :

fclean : clean
	rm -f $(NAME)

re : fclean all

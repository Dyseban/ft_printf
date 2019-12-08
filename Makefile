# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/03 14:34:05 by thgermai          #+#    #+#              #
#    Updated: 2019/12/08 17:51:31 by thgermai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf
SRCS = ./srcs/main.c\
		./srcs/ft_printf.c\
		./srcs/pf_arg.c\
		./srcs/pf_fill_1_5.c\
		./srcs/pf_fill_6_9.c\
		./srcs/pf_parcing.c\
		./srcs/pf_width.c\
		./srcs/pf_precision.c
INCLUDES = ./includes/ft_printf.h\
			./libft/libft.h
LIB = ./libft/libft.a
CFLAGS = -Wall -Wextra -Werror -g3
LOGFILE=$(LOGPATH) `date +'%y.%m.%d %H:%M:%S'`

all : $(NAME)

$(NAME) :
	@(make -C libft)
	@(gcc $(CFLAGS) $(LIB) $(SRCS) -I $(INCLUDES))
	@(./a.out)

f :
	@(make -C libft)
	@(gcc -g3 -fsanitize=address $(LIB) $(SRCS) -I $(INCLUDES))
	@(./a.out)

git : fclean
	git add *
	git commit -m "$(LOGFILE)"
	git push

clean :

clean libft :
	make fclean -C libft

fclean : clean libft clean
	rm -f a.out
	rm -rf a.out.dSYM

re : fclean all

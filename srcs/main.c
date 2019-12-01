/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:34:43 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/01 17:36:23 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

int main(void)
{
	char *str = ft_strdup("bonsoir a toute");
	//ft_printf("add : %p -> %s\n", str, str);
	printf("%s\n", ft_itoa_address((unsigned int)str, HEXADECIMAL));
	printf("address : %p -> %s\n", str, str);
//	system("leaks a.out");
	return (0);
}

/*
** 1 : c
** 2 : s
** 3 : p -> Il faut mettre un unsigned long et non unsigned int
** 4 : d
** 5 : i
** 6 : u
** 7 : x
** 8 : X
** 9 : %
*/

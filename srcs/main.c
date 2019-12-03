/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:34:43 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/03 14:09:41 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

int main(void)
{
	printf("\n|---- ft_print ----|\n\n");

	// int ret;
	char *str = ft_strdup("Salut a toute et a tous");
	// ret = ft_printf("\n%-s\n", str);
	// printf("\nret = %i\n", ret);
	// printf("%50s -|\n", str);
	t_param *param = parcing_param("%-10s");
	printf("width : %d\njustify : %d\nfill : %d\nspecifier : %d\n", param->width, param->justify, param->fill, param->specifier);
	printf("\n%s--|\n", fill_width_true(str, param));
	system("leaks a.out");
	return (0);
}

/*
** flags :
** - colle a droite au lieu de gauche dans la taille donne
** 0 repli la taille inutiliser de 0
** .
** * arguments dans le " " -> printf("%-*.*d", 10, 20, 30);
** taille minimal du champs donne un taille min et on complete dedans.
*/

//ret = ft_printf("index = %i -> address : %p -> %s\n", 48, str, str);

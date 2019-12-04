/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:34:43 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/04 15:15:07 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

int main(void)
{
	printf("\n|----		ft_print	----|\n\n");
	////////////	test section	////////////

	char *str = ft_strdup("Salut a toute et a tous");
	ft_printf("%10.50-s --|\n",str);
	//printf("\n%-050s --|\n",str);
	free(str);

	////////////	test section	////////////
	printf("\n|----		end		----|\n\n");
	//system("leaks a.out");
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
//printf("width : %d\njustify : %d\nfill : %d\nspecifier : %d\n", param->width, param->justify, param->fill, param->specifier);

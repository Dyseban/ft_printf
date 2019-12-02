/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:34:43 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/02 16:55:55 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

int main(void)
{
	int ret;
	char *str = ft_strdup("bonsoir a toute");
	ret = ft_printf("index = %i -> address : %p -> %s\n", 48, str, str);
	free(str);
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

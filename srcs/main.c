/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:34:43 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/02 14:02:31 by thgermai         ###   ########.fr       */
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
	ret = printf("%x\n", 12);
	//printf("%i\n", ret);
	free(str);
	//system("leaks a.out");
	return (0);
}

/*
** flags :
** -
** 0
** .
** *
** taille minimal du champs
*/

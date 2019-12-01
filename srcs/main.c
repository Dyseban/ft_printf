/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:34:43 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/01 15:44:07 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

int main(void)
{
	ft_printf("%i", 15);
	system("leaks a.out");
	return (0);
}

/*
** 1 : c -> putchar
** 2 : s -> putstr
** 3 : p -> whalla je sais pas
** 4 : d -> putnbr je pense
** 5 : i -> putnbr je suis quasi sur
** 6 : u -> ben pareil ... -> itoa base
** 7 : x -> hex donc je sais pas
** 8 : X -> HEX DONC JE SAIS PAS (mais en majuscule je pense)
** 9 : % -> strjoin(output, '%')
*/

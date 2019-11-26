/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:34:43 by thgermai          #+#    #+#             */
/*   Updated: 2019/11/26 15:20:22 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"

int main(void)
{
	char *s = ft_strdup("Salut a toute et a tous");
	ft_putnbr_base(&s, HEXADECIMAL);
	return (0);
}

/*
** c -> putchar
** s -> putstr
** p -> whalla je sais pas
** d -> putnbr je pense
** i -> putnbr je suis quasi sur
** u -> ben pareil ...
** x -> hex donc je sais pas
** X -> HEX DONC JE SAIS PAS (mais en majuscule je pense)
*/
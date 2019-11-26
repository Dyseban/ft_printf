/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgermain <thomasgermain@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:34:43 by thgermai          #+#    #+#             */
/*   Updated: 2019/11/26 19:47:16 by thomasgerma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

int main(void)
{
	ft_printf("Bonsoir a toute %s et a tous");
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:34:43 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/01 10:33:32 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

#include <fcntl.h>

int main(void)
{
	ft_printf("bonsoir a toute et a tous %s\n","salut");
	return (0);
}

/*
** c -> putchar
** s -> putstr
** p -> whalla je sais pas
** d -> putnbr je pense
** i -> putnbr je suis quasi sur
** u -> ben pareil ... -> itoa base
** x -> hex donc je sais pas
** X -> HEX DONC JE SAIS PAS (mais en majuscule je pense)
*/

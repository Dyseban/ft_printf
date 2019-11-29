/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:34:43 by thgermai          #+#    #+#             */
/*   Updated: 2019/11/29 15:58:18 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

int main(void)
{
	ft_printf("%x\n", 'a');
	printf("%x\n", 'j');
	return (0);
}

/*
** c -> putchar
** s -> putstr
** p -> whalla je sais pas
** d -> putnbr je pense
** i -> putnbr je suis quasi sur
** u -> ben pareil ... -> Atoi base
** x -> hex donc je sais pas
** X -> HEX DONC JE SAIS PAS (mais en majuscule je pense)
*/

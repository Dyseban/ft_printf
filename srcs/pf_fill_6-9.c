/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_fill_6-9.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:17:36 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/02 11:17:29 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

char		*pf_fill_unsi(va_list args, char *output)
{
	unsigned int		i;

	i = va_arg(args, unsigned int);
	output = ft_strjoin_f12(output, ft_itoa_unsigned(i));
	return (output);
}

char		*pf_fill_hexa(va_list args, char *output)
{
	int		i;

	i = va_arg(args, int);
	output = ft_strjoin_f12(output, ft_itoa_base(i, HEXADECIMAL));
	return (output);
}

char		*pf_fill_hexa_caps(va_list args, char *output)
{
	int		i;
	char	*temp;

	i = va_arg(args, int);
	temp = ft_itoa_base(i, HEXADECIMAL);
	i = -1;
	while (temp[++i])
		temp[i] = ft_toupper(temp[i]);
	output = ft_strjoin_f12(output, temp);
	return (output);
}

char		*pf_fill_modulo(va_list args, char *output)
{
	(void)args;
	output = ft_strjoin_f1(output, "%");
	return (output);
}

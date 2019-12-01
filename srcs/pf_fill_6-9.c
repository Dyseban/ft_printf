/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_fill_6-9.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:17:36 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/01 14:21:37 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

char		*pf_fill_unsi(va_list args, char *output)
{
	unsigned int		i;

	i = va_arg(args, unsigned int);
	output = ft_strjoin(output, ft_itoa_unsigned(i));
	return (output);
}

char		*pf_fill_hexa(va_list args, char *output)
{
	int		i;

	i = va_arg(args, int);
	output = ft_strjoin(output, ft_itoa_base(i, HEXADECIMAL));
	return (output);
}

char		*pf_fill_HEXA(va_list args, char *output)
{
	int		i;
	char	*temp;

	i = va_arg(args, int);
	temp = ft_itoa_base(i, HEXADECIMAL);
	i = 0;
	while (temp[i])
		ft_toupper(temp[i++]);
	output = ft_strjoin(output, temp);
	return (output);
}

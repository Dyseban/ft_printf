/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_fill_6_9.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:17:36 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/14 16:30:01 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				pf_fill_unsi(va_list args, t_param *param)
{
	unsigned int		i;
	char				*num;

	i = va_arg(args, unsigned int);
	num = ft_itoa_unsigned(i);
	if (param->precision != -1)
		num = fill_precision(num, param);
	if (param->width)
	{
		if (param->justify == LEFT)
			num = fill_width_left(num, param);
		else
			num = fill_width_right(num, param);
	}
	ft_putstr_fd(num, 1);
	return (ft_exit(ft_strlen(num), 2, num, param));
}

int				pf_fill_hexa(va_list args, t_param *param)
{
	int		i;
	char	*num;

	i = va_arg(args, int);
	num = ft_itoa_base(i, HEXADECIMAL);
	if (param->precision != -1)
		num = fill_precision(num, param);
	if (param->width)
	{
		if (param->justify == LEFT)
			num = fill_width_left(num, param);
		else
			num = fill_width_right(num, param);
	}
	ft_putstr_fd(num, 1);
	return (ft_exit(ft_strlen(num), 2, num, param));
}

int				pf_fill_hexa_caps(va_list args, t_param *param)
{
	int		i;
	char	*num;

	i = va_arg(args, int);
	num = ft_itoa_base(i, HEXADECIMAL);
	i = -1;
	while (num[++i])
		num[i] = ft_toupper(num[i]);
	if (param->precision != -1)
		num = fill_precision(num, param);
	if (param->width)
	{
		if (param->justify == LEFT)
			num = fill_width_left(num, param);
		else
			num = fill_width_right(num, param);
	}
	ft_putstr_fd(num, 1);
	return (ft_exit(ft_strlen(num), 2, num, param));
}

int				pf_fill_modulo(va_list args, t_param *param)
{
	char *temp;

	(void)args;
	if (!(temp = ft_strdup("%")))
		return (ft_exit(-1, 1, param));
	if (param->width)
	{
		if (param->justify == LEFT)
			temp = fill_width_left(temp, param);
		else
			temp = fill_width_right(temp, param);
	}
	ft_putstr_fd(temp, 1);
	return (ft_exit(ft_strlen(temp), 2, temp, param));
}

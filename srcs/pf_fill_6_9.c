/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_fill_6_9.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgermain <thomasgermain@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:17:36 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/25 17:06:34 by thomasgerma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				pf_fill_unsi(va_list args, t_param *param)
{
	unsigned int		i;
	char				*num;

	i = va_arg(args, unsigned int);
	if (param->precision)
		num = ft_itoa_unsigned(i);
	else
		num = ft_strdup("");
	if (param->precision != -1)
	{
		num = fill_precision(num, param);
		param->fill = ' ';
	}
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
	if (param->precision)
		num = ft_itoa_base(i, HEXADECIMAL);
	else
		num = ft_strdup("");
	if (param->precision != -1)
	{
		num = fill_precision(num, param);
		param->fill = ' ';
	}
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
	if (param->precision)
	{
		num = ft_itoa_base(i, HEXADECIMAL);
		i = -1;
		while (num[++i])
			num[i] = ft_toupper(num[i]);
	}
	else
		num = ft_strdup("");
	if (param->precision != -1)
	{
		num = fill_precision(num, param);
		param->fill = ' ';
	}
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_fill_1_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:13:41 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/14 13:41:58 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				pf_fill_char(va_list args, t_param *param)
{
	char	c;
	char	*str;

	if (!(str = malloc(sizeof(char) * 2)))
		return (ft_exit(-1, 1, param));
	c = va_arg(args, int);
	str[0] = c;
	str[1] = '\0';
	if (param->width)
	{
		if (param->justify == LEFT)
			str = fill_width_left(str, param);
		else
			str = fill_width_right(str, param);
	}
	ft_putstr_fd(str, 1);
	return (ft_exit(ft_strlen(str), 2, str, param));
}

int				pf_fill_str(va_list args, t_param *param)
{
	char	*str;
	char	*temp;

	str = va_arg(args, char *);
	if (param->precision != -1 && param->precision < (int)ft_strlen(str))
	{
		str = ft_substr(str, 0, param->precision);
		temp = ft_strdup(str);
		free(str);
	}
	else
		temp = ft_strdup(str);
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

int				pf_fill_add(va_list args, t_param *param)
{
	void					*ptr;
	char					*result;

	ptr = va_arg(args, void *);
	if (!ptr)
	{
		ft_putstr_fd("0x0", 1);
		return (ft_exit(3, 1, param));
	}
	result = ft_itoa_address((unsigned long long int)ptr);
	if (param->precision)
		result = fill_precision(result, param);
	result = ft_strjoin_f2("0x", result);
	if (param->width)
	{
		if (param->justify == LEFT)
			result = fill_width_left(result, param);
		else
			result = fill_width_right(result, param);
	}
	ft_putstr_fd(result, 1);
	return (ft_exit(ft_strlen(result), 2, result, param));
}

int				pf_fill_deci(va_list args, t_param *param)
{
	int		i;
	int		neg;
	char	*num;

	neg = 0;
	if ((i = va_arg(args, int)) < 0)
	{
		i *= -1;
		neg = 1;
		param->width -= 1;
	}
	num = ft_itoa(i);
	if (param->precision)
		num = fill_precision(num, param);
	if (param->width)
	{
		if (param->justify == LEFT)
			num = fill_width_left(num, param);
		else
			num = fill_width_right(num, param);
	}
	if (neg)
		num = ft_strjoin_f2("-", num);
	ft_putstr_fd(num, 1);
	return (ft_exit(ft_strlen(num), 2, num, param));
}

int				pf_fill_int(va_list args, t_param *param)
{
	int		i;
	int		neg;
	char	*num;

	neg = 0;
	if ((i = va_arg(args, int)) < 0)
	{
		i *= -1;
		neg = 1;
		param->width -= 1;
	}
	num = ft_itoa(i);
	if (param->precision)
		num = fill_precision(num, param);
	if (param->width)
	{
		if (param->justify == LEFT)
			num = fill_width_left(num, param);
		else
			num = fill_width_right(num, param);
	}
	if (neg)
		num = ft_strjoin_f2("-", num);
	ft_putstr_fd(num, 1);
	return (ft_exit(ft_strlen(num), 2, num, param));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_fill_1_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgermain <thomasgermain@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:13:41 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/26 16:31:58 by thomasgerma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				pf_fill_char(va_list args, t_param *param)
{
	char	c;
	char	*str;

	c = va_arg(args, int);
	if (c)
	{
		if (!(str = malloc(sizeof(char) * 2)))
			return (ft_exit(-1, 1, param));
		str[0] = c;
		str[1] = '\0';
	}
	else
		str = ft_strdup("\x00");
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
/* str a revoir je pense que j'etais bouteiller quand j'ai ecrit ca !! */
int				pf_fill_str(va_list args, t_param *param)
{
	char	*str;
	char	*temp;

	if (!(str = va_arg(args, char *)))
		str = ft_strdup("(null)");
	if (param->precision != -1 && param->precision < (int)ft_strlen(str))
	{
		str = ft_substr(str, 0, param->precision);
		temp = ft_strdup(str);
		free(str);
	}
	else if (!param->precision)
		temp = ft_strdup("");
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
		result = ft_strdup("0");
	else
		result = ft_itoa_address((unsigned long long int)ptr);
	if (param->precision != -1 && param->precision)
	{
		result = fill_precision(result, param);
		param->fill = ' ';
	}
	else if (param->precision == 0)
	{
		free(result);
		result = ft_strdup("");
	}
	result = ft_strjoin_f2("0x", result);
	result = check_width_num(result, param);
	ft_putstr_fd(result, 1);
	return (ft_exit(ft_strlen(result), 2, result, param));
}

int				pf_fill_deci(va_list args, t_param *param)
{
	int		i;
	char	*num;
	char	*temp;

	temp = NULL;
	i = va_arg(args, int);
	if (param->precision != 0)
		num = ft_itoa(i);
	else
		num = ft_strdup("");
	if (param->precision != -1)
	{
		num = check_precision_num(num, param);
		param->fill = ' ';
	}
	num = check_width_num(num, param);
	ft_putstr_fd(num, 1);
	return (ft_exit(ft_strlen(num), 2, num, param));
}

int				pf_fill_int(va_list args, t_param *param)
{
	int		i;
	char	*num;
	char	*temp;

	temp = NULL;
	i = va_arg(args, int);
	if (param->precision != 0)
		num = ft_itoa(i);
	else
		num = ft_strdup("");
	if (param->precision != -1)
	{
		num = check_precision_num(num, param);
		param->fill = ' ';
	}
	num = check_width_num(num, param);
	ft_putstr_fd(num, 1);
	return (ft_exit(ft_strlen(num), 2, num, param));
}

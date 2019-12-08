/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_fill_1-5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:13:41 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/08 09:55:53 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

char		*pf_fill_char(va_list args, char *output, t_param *param)
{
	char	c;
	char	*str;

	if (!(str = malloc(sizeof(char) * 2)))
		return (NULL);
	c = va_arg(args, int);
	str[0] = c;
	str[1] = '\0';
	if (param->width)
	{
		if (param->justify == LEFT)
			str = fill_width_left(str, param);
		else
			str = fill_width_right(str, param);
		output = ft_strjoin_f12(output, str);
	}
	else
		output = ft_strjoin_f12(output, str);
	return (output);
}

char		*pf_fill_str(va_list args, char *output, t_param *param)
{
	char	*str;

	str = va_arg(args, char *);
	if (param->width)
	{
		if (param->justify == LEFT)
			str = fill_width_left(str, param);
		else
			str = fill_width_right(str, param);
		output = ft_strjoin_f12(output, str);
	}
	else
		output = ft_strjoin_f1(output, str);
	return (output);
}

char		*pf_fill_add(va_list args, char *output, t_param *param)
{
	void					*ptr;
	char					*result;

	ptr = va_arg(args, void *);
	result = ft_itoa_address((unsigned long long int)ptr);
	if (param->precision)
		result = fill_precision(result, param);
	result = ft_strjoin_f2("0x", result);
	return (output = ft_strjoin_f12(output, result));
}

char		*pf_fill_deci(va_list args, char *output, t_param *param)
{
	int		i;
	char	*num;

	i = va_arg(args, int);
	num = ft_itoa(i);
	if (param->precision)
		num = fill_precision(num, param);
	return (output = ft_strjoin_f12(output, num));
}

char		*pf_fill_int(va_list args, char *output, t_param *param)
{
	int		i;
	char	*num;

	i = va_arg(args, int);
	num = ft_itoa(i);
	if (param->precision)
		num = fill_precision(num, param);
	return (output = ft_strjoin_f12(output, num));
}

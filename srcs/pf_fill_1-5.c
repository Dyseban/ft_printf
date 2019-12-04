/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_fill_1-5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgermain <thomasgermain@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:13:41 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/04 19:33:02 by thomasgerma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

char		*pf_fill_char(va_list args, char *output, t_param *param)
{
	char	c;
	char	*str;

	c = va_arg(args, int);
	if (param->width)
	{
		if (param->justify == LEFT)
			str = fill_width_left(&c, param);
		else
			str = fill_width_right(&c, param);
		output = ft_strjoin_f1(output, &c);
	}
	output = ft_strjoin_f1(output, &c);
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
	result = ft_strjoin_f2("0x", result);
	return (output = ft_strjoin_f12(output, result));
}

char		*pf_fill_deci(va_list args, char *output, t_param *param)
{
	int		i;

	i = va_arg(args, int);
	return (output = ft_strjoin_f12(output, ft_itoa(i)));
}

char		*pf_fill_int(va_list args, char *output, t_param *param)
{
	int		i;

	i = va_arg(args, int);
	return (output = ft_strjoin_f12(output, ft_itoa(i)));
}

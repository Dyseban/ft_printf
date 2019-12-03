/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_fill_1-5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:13:41 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/03 13:50:18 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

char		*pf_fill_char(va_list args, char *output, t_param *param)
{
	char	c;

	c = va_arg(args, int);
	output = ft_strjoin_f1(output, &c);
	return (output);
}

char		*pf_fill_str(va_list args, char *output, t_param *param)
{
	char	*str;

	str = va_arg(args, char *);
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

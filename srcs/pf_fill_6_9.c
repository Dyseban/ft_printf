/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_fill_6_9.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:17:36 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/08 13:18:38 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

char		*pf_fill_unsi(va_list args, char *output, t_param *param)
{
	unsigned int		i;
	char				*num;

	i = va_arg(args, unsigned int);
	num = ft_itoa_unsigned(i);
	if (param->precision)
		num = fill_precision(num, param);
	free(param);
	return (output = ft_strjoin_f12(output, num));
}

char		*pf_fill_hexa(va_list args, char *output, t_param *param)
{
	int		i;
	char	*num;

	i = va_arg(args, int);
	num = ft_itoa_base(i, HEXADECIMAL);
	if (param->precision)
		num = fill_precision(num, param);
	free(param);
	return (output = ft_strjoin_f12(output, num));
}

char		*pf_fill_hexa_caps(va_list args, char *output, t_param *param)
{
	int		i;
	char	*temp;

	i = va_arg(args, int);
	temp = ft_itoa_base(i, HEXADECIMAL);
	i = -1;
	while (temp[++i])
		temp[i] = ft_toupper(temp[i]);
	if (param->precision)
		temp = fill_precision(temp, param);
	free(param);
	return (output = ft_strjoin_f12(output, temp));
}

char		*pf_fill_modulo(va_list args, char *output, t_param *param)
{
	(void)args;
	free(param);
	return (output = ft_strjoin_f1(output, "%"));
}

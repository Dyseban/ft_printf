/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgermain <thomasgermain@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 09:23:27 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/17 12:57:59 by thomasgerma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char			*fill_precision(char *str, t_param *param)
{
	char		*temp;

	if ((int)ft_strlen(str) >= param->precision)
		return (str);
	if (!(temp = malloc(sizeof(char) * (param->precision - ft_strlen(str) + 1))))
		return (NULL);
	ft_memset(temp, '0', param->precision - ft_strlen(str));
	temp[param->precision - ft_strlen(str)] = '\0';
	return (temp = ft_strjoin_f12(temp, str));
}

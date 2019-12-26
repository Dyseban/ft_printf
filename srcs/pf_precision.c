/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgermain <thomasgermain@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 09:23:27 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/26 16:17:18 by thomasgerma      ###   ########.fr       */
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

char			*check_precision_num(char *str, t_param *param)
{
	char *temp;
	char *num;

	num = ft_strdup(str);
	free(str);
	temp = NULL;
	if (param->precision != -1)
	{
		if (num[0] == '-')
		{
			temp = ft_strdup(num + 1);
			free(num);
			num = ft_strjoin_f2("-", fill_precision(temp, param));
		}
		else
			num = fill_precision(num, param);
	}
	return (num);
}

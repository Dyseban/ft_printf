/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgermain <thomasgermain@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 13:37:50 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/26 16:01:58 by thomasgerma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*fill_width_right(char *str, t_param *param)
{
	char	*temp;

	if ((int)ft_strlen(str) > param->width)
		return (str);
	if (!(temp = malloc(sizeof(char) * (param->width - ft_strlen(str)))))
		return (NULL);
	ft_memset(temp, param->fill, param->width - ft_strlen(str));
	temp[param->width - ft_strlen(str)] = '\0';
	return (temp = ft_strjoin_f12(temp, str));
}

char		*fill_width_left(char *str, t_param *param)
{
	char	*temp;

	if ((int)ft_strlen(str) > param->width)
		return (str);
	if (!(temp = malloc(sizeof(char) * (param->width - ft_strlen(str)))))
		return (NULL);
	ft_memset(temp, param->fill, param->width - ft_strlen(str));
	temp[param->width - ft_strlen(str)] = '\0';
	return (temp = ft_strjoin_f12(str, temp));
}

char		*check_width_num(char *str, t_param *param)
{
	char *num;
	char *temp;

	if (!param->width)
		return (str);
	num = ft_strdup(str);
	free(str);
	if (param->width)
	{
		if (num[0] == '-' && param->fill == '0')
		{
			temp = ft_strdup(num + 1);
			free(num);
			param->width--;
			if (param->justify == LEFT)
				num = ft_strjoin_f2("-", fill_width_left(temp, param));
			else
				num = ft_strjoin_f2("-", fill_width_right(temp, param));
		}
		else if (param->justify == LEFT)
			num = fill_width_left(num, param);
		else
			num = fill_width_right(num, param);
	}
	return (num);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 09:23:27 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/08 13:54:49 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

char			*fill_precision(char *str, t_param *param)
{
	char		*temp;

	if ((int)ft_strlen(str) > param->precision)
		return (str);
	if (!(temp = malloc(sizeof(char) * param->precision)))
		return (NULL);
	ft_memset(temp, '0', param->precision - ft_strlen(str));
	return (temp = ft_strjoin_f12(temp, str));
}

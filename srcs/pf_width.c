/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 13:37:50 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/08 14:13:07 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

char		*fill_width_right(char *str, t_param *param)
{
	char	*temp;

	if ((int)ft_strlen(str) > param->width)
		return (str);
	if (!(temp = malloc(sizeof(char) * (param->width - ft_strlen(str)))))
		return (NULL);
	ft_memset(temp, param->fill, param->width - ft_strlen(str));
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
	return (temp = ft_strjoin_f12(str, temp));
}

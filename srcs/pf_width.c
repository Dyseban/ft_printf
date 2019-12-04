/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 13:37:50 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/04 14:34:18 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

char		*fill_width_right(char *str, t_param *param)
{
	char	*temp;

	if ((int)ft_strlen(str) > param->width)
		return (temp = ft_strdup(str));
	if (!(temp = malloc(sizeof(char) * param->width)))
		return (NULL);
	ft_memset(temp, param->fill, param->width - ft_strlen(str));
	temp = ft_strjoin_f1(temp, str);
	return (temp);
}

char		*fill_width_left(char *str, t_param *param)
{
	char	*temp;

	if ((int)ft_strlen(str) > param->width)
		return (temp = ft_strdup(str));
	if (!(temp = malloc(sizeof(char) * param->width)))
		return (NULL);
	ft_memset(temp, param->fill, param->width - ft_strlen(str));
	temp = ft_strjoin_f2(str, temp);
	return (temp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 13:37:50 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/03 14:11:38 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

char		*fill_width_false(char *str, t_param *param)
{
	char	*temp;

	if (!(temp = malloc(sizeof(char) * param->width)))
		return (NULL);
	ft_memset(temp, param->fill, param->width - ft_strlen(str));
	temp = ft_strjoin_f12(temp, str);
	return (temp);
}

char		*fill_width_true(char *str, t_param *param)
{
	char	*temp;

	if (!(temp = malloc(sizeof(char) * param->width)))
		return (NULL);
	ft_memset(temp, param->fill, param->width - ft_strlen(str));
	temp = ft_strjoin_f12(str, temp);
	return (temp);
}

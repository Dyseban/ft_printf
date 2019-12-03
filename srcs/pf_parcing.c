/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parcing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 10:35:16 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/03 10:59:35 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

t_param		*set_put_param(void)
{
	t_param *param;

	if(!(param = malloc(sizeof(t_param))))
		return (NULL);
	param->specifier = 0;
	param->width = 0;
	param->justify = RIGHT;
	param->fill = ' ';
	return (param);
}

t_param		*parcing_param(const char *str)
{
	int			i;
	char		*flags;
	t_param		*param;

	param = set_put_param();
	flags = ft_strdup(VALID_FLAGS);
	i = 0;
	if (str[i] != '%')
		return (NULL);
	i++;
	while (ft_strchr(flags, str[i]) || ft_isdigit(str[i]))
	{
		if (str[i] == '-')
			param->justify = LEFT;
		else if (str[i] == '0' && !param->width)
			param->fill = '0';
		else if (!param->width)
			param->width = ft_atoi(str + i);
		i++;
	}
	param->specifier = define_type(str[i]);
	free(flags);
	return (param);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 19:34:40 by thomasgerma       #+#    #+#             */
/*   Updated: 2019/12/01 14:25:09 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int			nb_args(const char *str)
{
	int		nb_args;
	char	*conver;

	conver = ft_strdup("cspdiuxX");
	nb_args = 0;
	while (*str)
	{
		if (*str == '%' && ft_strchr(conver, str[1]))
			nb_args++;
		str++;
	}
	free(conver);
	return (nb_args);
}

int			next_arg_index(const char *str)
{
	int		i;

	i = 0;
	while (*str)
	{
		if (ft_define_type(str) > 0)
			return (i);
		str++;
		i++;
	}
	return (i);
}

char		*pf_fill_deci(va_list args, char *output)
{
	int		i;

	i = va_arg(args, int);
	output = ft_strjoin(output, ft_itoa(i));
	return (output);
}

char		*pf_fill_modulo(va_list args, char *output)
{
	(void)args;
	output = ft_strjoin(output, "%");
	return (output);
}

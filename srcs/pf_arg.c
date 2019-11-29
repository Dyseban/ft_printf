/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 19:34:40 by thomasgerma       #+#    #+#             */
/*   Updated: 2019/11/29 14:14:44 by thgermai         ###   ########.fr       */
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
		if (ft_define_type(str))
			return (i);
		str++;
		i++;
	}
	return (i);
}

char		*fill_arg(char *output, va_list args, int type)
{
	char			c;
	unsigned int	u;
	int				i;
	char			*str;

	if (type == 1)
	{
		c = va_arg(args, int);
		output = ft_strjoin(output, &c);
	}
	if (type == 2)
	{
		str = va_arg(args, char *);
		output = ft_strjoin(output, str);
	}
	if (type == 4 || type == 5)
	{
		i = va_arg(args, int);
		output = ft_strjoin(output, ft_itoa(i));
	}
	if (type == 6)
	{
		u = va_arg(args, unsigned int);
		output = ft_strjoin(output, ft_itoa_unsigned(u));
	}
	if (type == 9)
		output = ft_strjoin(output, "%");
	return (output);
}

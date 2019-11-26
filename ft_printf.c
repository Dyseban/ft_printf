/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:10:20 by thgermai          #+#    #+#             */
/*   Updated: 2019/11/26 15:01:04 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

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

int			ft_detect_type(char *str)
{
	while (*str)
	{
		if (*str == '%' && str[1] == 'c')
			return (1);
		else if (*str == '%' && str[1] == 's')
			return (2);
		else if (*str == '%' && str[1] == 'p')
			return (3);
		else if (*str == '%' && str[1] == 'd')
			return (4);
		else if (*str == '%' && str[1] == 'i')
			return (5);
		else if (*str == '%' && str[1] == 'u')
			return (6);
		else if (*str == '%' && str[1] == 'x')
			return (7);
		else if (*str == '%' && str[1] == 'X')
			return (8);
		str++;
	}
	return (0);
}

int			ft_printf(const char *str, ...)
{
	va_list args;
	int num_args;
	int i;

	i = 0;
	num_args = nb_args(str);
	va_start(args, str);
	if (!num_args)
	{
		ft_putstr_fd((char *)str, 1);
		return (ft_strlen(str));
	}

	va_end(args);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgermain <thomasgermain@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:10:20 by thgermai          #+#    #+#             */
/*   Updated: 2019/11/26 20:29:10 by thomasgerma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int				ft_define_type(const char *str)
{
	if (*str && str[1])
	{
		if (*str == '%' && str[1] == 'c')
			return (1);
		else if (*str == '%' && str[1] == 's')
			return (1);
		else if (*str == '%' && str[1] == 'p')
			return (1);
		else if (*str == '%' && str[1] == 'd')
			return (1);
		else if (*str == '%' && str[1] == 'i')
			return (1);
		else if (*str == '%' && str[1] == 'u')
			return (1);
		else if (*str == '%' && str[1] == 'x')
			return (1);
		else if (*str == '%' && str[1] == 'X')
			return (1);
	}
	return (0);
}

const char		*ft_refresh_str(const char *str, int i)
{
	char			*temp;

	if (str[i])
	{
		temp = ft_strdup(str + i + 1);
		if (str)
			free((char *)str);
		str = temp;
	}
	else
	{
		if (str)
			free((char *)str);
		str = NULL;
	}
	return (str);
}

int				ft_printf(const char *str, ...)
{
	va_list		args;
	char		*output;
	int 		num_args;
	int 		i;

	i = 0;
	num_args = nb_args(str);
	va_start(args, str);
	while (*str)
	{
		if (!(output = ft_substr(str, 0, next_arg_index(str))))
			return (-1);
		ft_putstr_fd(output, 1);
		str = str + next_arg_index(str) + 2;
	}
	va_end(args);
	return (0);
}

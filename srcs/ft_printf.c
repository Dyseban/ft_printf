/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgermain <thomasgermain@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:10:20 by thgermai          #+#    #+#             */
/*   Updated: 2019/11/28 10:26:01 by thomasgerma      ###   ########.fr       */
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
	}
	return (0);
}

const char		*ft_refresh_str(const char *str)
{
	int				next_arg;

	next_arg = next_arg_index(str);
	if (str[next_arg] == '%')
		str = str + next_arg + 2;
	else
		str = str + next_arg;
	return (str);
}

int				ft_printf(const char *str, ...)
{
	va_list		args;
	char		*output;
	int 		num_args;
	int 		i;

	i = 0;
	if (!(output = ft_calloc(sizeof(char), 1)))
		return (-1);
	num_args = nb_args(str);
	va_start(args, str);
	while (*str)
	{
		if (!(output = ft_strjoin(output, ft_substr(str, 0, next_arg_index(str)))))
			return (-1);
		output = fill_arg(output, args,
			ft_define_type(str + next_arg_index(str)));
		str = ft_refresh_str(str);
	}
	ft_putstr_fd(output, 1);
	va_end(args);
	return (ft_strlen(output));
}

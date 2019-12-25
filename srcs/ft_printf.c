/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgermain <thomasgermain@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 11:20:40 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/25 16:53:47 by thomasgerma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

const char		*ft_refresh_str(const char *str)
{
	int				next_arg;

	next_arg = next_arg_index(str);
	if (str[next_arg] == '%')
	{
		next_arg++;
		while (str[next_arg] && define_type(str[next_arg]) == -1)
			next_arg++;
		next_arg++;
	}
	return (str + next_arg);
}

int			redict_type(va_list args, t_param *param)
{
	int		(*fptr[9])(va_list, t_param *);

	if (!param)
		return (-1);
	if (param->specifier < 0)
		return (ft_exit(-1, 1, param));
	fptr[0] = &pf_fill_char;
	fptr[1] = &pf_fill_str;
	fptr[2] = &pf_fill_add;
	fptr[3] = &pf_fill_deci;
	fptr[4] = &pf_fill_int;
	fptr[5] = &pf_fill_unsi;
	fptr[6] = &pf_fill_hexa;
	fptr[7] = &pf_fill_hexa_caps;
	fptr[8] = &pf_fill_modulo;
	return ((*fptr[param->specifier])(args, param));
}

int				ft_printf(const char *str, ...)
{
	va_list		args;
	char		*output;
	int			i;
	int			j;

	j = 0;
	i = 0;
	output = NULL;
	va_start(args, str);
	while (*str)
	{
		if (output)
			free(output);
		if (!(output = ft_substr(str, 0, next_arg_index(str))))
			return (ft_exit(-1, 0));
		i += ft_strlen(output);
		ft_putstr_fd(output, 1);
		if (str[next_arg_index(str)] == '%')
		{
			j = redict_type(args, parcing_param(str + next_arg_index(str), args));
			if (j == -1)
			{
				va_end(args);
				return (ft_exit(i, 1, output));
			}
			i += j;
		}
		str = ft_refresh_str(str);
	}
	va_end(args);
	return (ft_exit(i, 1, output));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:10:20 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/03 13:33:26 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

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

char			*redict_type(va_list args, char *output, t_param *param)
{
	char *(*fptr[9])(va_list, char *, t_param *);

	if (param->specifier < 0)
	{
		printf("wrong specifier\n");
		free(param);
		return (NULL);
	}
	fptr[0] = &pf_fill_char;
	fptr[1] = &pf_fill_str;
	fptr[2] = &pf_fill_add;
	fptr[3] = &pf_fill_deci;
	fptr[4] = &pf_fill_int;
	fptr[5] = &pf_fill_unsi;
	fptr[6] = &pf_fill_hexa;
	fptr[7] = &pf_fill_hexa_caps;
	fptr[8] = &pf_fill_modulo;
	return (output = (*fptr[param->specifier])(args, output, param));
}

int				ft_printf(const char *str, ...)
{
	va_list		args;
	char		*output;
	int			i;

	i = 0;
	if (!(output = ft_calloc(sizeof(char), 1)))
		return (-1);
	va_start(args, str);
	while (*str)
	{
		if (!(output = ft_strjoin_f12(output, ft_substr(str, 0, next_arg_index(str)))))
			return (ft_exit(-1, 1, output));
		if (str[next_arg_index(str)] == '%')
			if (!(output = redict_type(args, output, parcing_param(str + next_arg_index(str)))))
				return (ft_exit(-1, 1, output));
		str = ft_refresh_str(str);
	}
	ft_putstr_fd(output, 1);
	va_end(args);
	return (ft_exit(ft_strlen(output), 1, output));
}

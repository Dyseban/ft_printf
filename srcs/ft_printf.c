/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:10:20 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/02 17:03:28 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int				ft_define_type(const char *str)
{
	int		i;
	char	*value;

	i = 0;
	value = ft_strdup(VALID_VALUE);
	if (str[0] != '%')
		return (ft_exit(-1, 1, value));
	while (value[i] && value[i] != str[1])
		i++;
	if (value[i])
		return (ft_exit(i + 1, 1, value));
	return (ft_exit(-1, 1, value));
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

char			*redict_type(va_list args, char *output, int type)
{
	char *(*fptr[9])(va_list, char *);

	fptr[0] = &pf_fill_char;
	fptr[1] = &pf_fill_str;
	fptr[2] = &pf_fill_add;
	fptr[3] = &pf_fill_deci;
	fptr[4] = &pf_fill_int;
	fptr[5] = &pf_fill_unsi;
	fptr[6] = &pf_fill_hexa;
	fptr[7] = &pf_fill_hexa_caps;
	fptr[8] = &pf_fill_modulo;
	return (output = (*fptr[type - 1])(args, output));
}

int				ft_printf(const char *str, ...)
{
	va_list		args;
	char		*output;
	int			num_args;
	int			i;

	i = 0;
	if (!(output = ft_calloc(sizeof(char), 1)))
		return (-1);
	num_args = nb_args(str);
	va_start(args, str);
	while (*str)
	{
		if (!(output = ft_strjoin_f12(output, ft_substr(str, 0, next_arg_index(str)))))
			return (-1);
		if (str[next_arg_index(str)] == '%')
			output = redict_type(args, output, ft_define_type(str + next_arg_index(str)));
		str = ft_refresh_str(str);
	}
	ft_putstr_fd(output, 1);
	va_end(args);
	return (ft_exit(ft_strlen(output), 1, output));
}

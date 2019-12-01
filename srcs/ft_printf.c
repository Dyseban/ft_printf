/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:10:20 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/01 10:33:16 by thgermai         ###   ########.fr       */
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

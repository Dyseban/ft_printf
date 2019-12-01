/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_fill_1-5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:13:41 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/01 14:16:50 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

char		*pf_fill_char(va_list args, char *output)
{
	char	c;

	c = va_arg(args, int);
	output = ft_strjoin(output, &c);
	return (output);
}

char		*pf_fill_str(va_list args, char *output)
{
	char	*str;

	str = va_arg(args, char *);
	output = ft_strjoin(output, str);
	return (output);
}

char		*pf_fill_deci(va_list args, char *output)
{
	int		i;

	i = va_arg(args, int);
	output = ft_strjoin(output, ft_itoa(i));
	return (output);
}

char		*pf_fill_int(va_list args, char *output)
{
	int		i;

	i = va_arg(args, int);
	output = ft_strjoin(output, ft_itoa(i));
	return (output);
}



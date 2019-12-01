/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_fill_1-5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:13:41 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/01 17:08:21 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

char		*pf_fill_char(va_list args, char *output)
{
	char	c;

	c = va_arg(args, int);
	output = ft_strjoin_f1(output, &c);
	return (output);
}

char		*pf_fill_str(va_list args, char *output)
{
	char	*str;

	str = va_arg(args, char *);
	output = ft_strjoin_f1(output, str);
	return (output);
}

char		*pf_fill_add(va_list args, char *ouput)
{
	char	*ptr;

	ptr = va_arg(args, char *);
	printf("%x", (unsigned int)ptr);
	return (NULL);
}

char		*pf_fill_deci(va_list args, char *output)
{
	int		i;

	i = va_arg(args, int);
	output = ft_strjoin_f12(output, ft_itoa(i));
	return (output);
}

char		*pf_fill_int(va_list args, char *output)
{
	int		i;

	i = va_arg(args, int);
	output = ft_strjoin_f12(output, ft_itoa(i));
	return (output);
}



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgermain <thomasgermain@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 10:35:16 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/25 16:53:06 by thomasgerma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_param		*set_put_param(void)
{
	t_param *param;

	if (!(param = malloc(sizeof(t_param))))
		return (NULL);
	param->specifier = 0;
	param->precision = -1;
	param->width = 0;
	param->justify = RIGHT;
	param->fill = ' ';
	return (param);
}

int			get_value(va_list args)
{
	int		value;

	value = va_arg(args, int);
	if (value == -1)
		return (-1);
	return (value);
}

void		assigning_param(const char *str, t_param **param, va_list args)
{
	char		*flags;

	flags = ft_strdup(VALID_FLAGS);
	while (ft_find_in(flags, *str) || ft_isdigit(*str))
	{
		if (*str == '-')
			(*param)->justify = LEFT;
		else if (*str == '.')
		{
			if (*(str + 1) == '*')
				(*param)->precision = get_value(args);
			else
				(*param)->precision = ft_atoi(str + 1);
			while (ft_isdigit(*(str + 1)))
				str++;
		}
		else if (*str == '0' && !(*param)->width)
			(*param)->fill = '0';
		else if (*str == '*' && !(*param)->width)
			(*param)->width = get_value(args);
		else if (!(*param)->width)
			(*param)->width = ft_atoi(str);
		str++;
	}
	free(flags);
	(*param)->specifier = define_type(*str);
}

t_param		*parcing_param(const char *str, va_list args)
{
	t_param		*param;

	if (*str != '%')
		return (NULL);
	if (!(param = set_put_param()))
		return (NULL);
	str++;
	assigning_param(str, &param, args);
	if (param->fill == '0' && param->justify == LEFT)
		param->fill = ' ';
	//printf("precision : %d\nwidth : %d\njustify : %d\nfill : %d\nspecifier : %d\n",param->precision, param->width, param->justify, param->fill, param->specifier);
	return (param);
}

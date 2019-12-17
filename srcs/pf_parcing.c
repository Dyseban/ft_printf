/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgermain <thomasgermain@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 10:35:16 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/17 10:37:10 by thomasgerma      ###   ########.fr       */
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

int		assigning_param(const char *str, t_param **param, va_list args)
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
			{
				if (!((*param)->precision = get_value(args)))
					return (ft_exit(0, 1, flags));
			}
			else
			{
				if (!((*param)->precision = ft_atoi(str + 1)))
					return (ft_exit(0, 1, flags));
			}
			while (ft_isdigit(*(str + 1)))
				str++;
		}
		else if (*str == '0' && !(*param)->width)
			(*param)->fill = '0';
		else if (*str == '*' && !(*param)->width)
		{
			if (!((*param)->width = get_value(args)))
				return (ft_exit(0, 1, flags));
		}
		else if (!(*param)->width)
		{
			if (!((*param)->width = ft_atoi(str)))
				return (ft_exit(0, 1, flags));
		}
		str++;
	}
	(*param)->specifier = define_type(*str);
	return (ft_exit(1, 1, flags));
}

t_param		*parcing_param(const char *str, va_list args)
{
	t_param		*param;

	if (*str != '%')
		return (NULL);
	if (!(param = set_put_param()))
		return (NULL);
	str++;
	if (!(assigning_param(str, &param, args)))
	{
		free(param);
		return (NULL);
	}
	if (param->fill == '0' && param->justify == LEFT)
		param->fill = ' ';
	//printf("precision : %d\nwidth : %d\njustify : %d\nfill : %d\nspecifier : %d\n",param->precision, param->width, param->justify, param->fill, param->specifier);
	return (param);
}

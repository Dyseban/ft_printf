/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parcing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 10:35:16 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/03 10:59:35 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

t_param		*set_put_param(void)
{
	t_param *param;

	if(!(param = malloc(sizeof(t_param))))
		return (NULL);
	param->specifier = 0;
	param->precision = 0;
	param->width = 0;
	param->justify = RIGHT;
	param->fill = ' ';
	return (param);
}

void		assisning_param(const char *str, t_param **param)
{
	char		*flags;

	flags = ft_strdup(VALID_FLAGS);
	while (ft_find_in(flags, *str) || ft_isdigit(*str))
	{
		if (*str == '-')
			(*param)->justify = LEFT;
		else if (*str == '.')
		{
			(*param)->precision = ft_atoi(++str);
			while (ft_isdigit(*(str + 1)))
				str++;
		}
		else if (*str == '0' && !(*param)->width)
			(*param)->fill = '0';
		else if (!(*param)->width)
			(*param)->width = ft_atoi(str);
		str++;
	}
	(*param)->specifier = define_type(*str);
	free(flags);
}

t_param		*parcing_param(const char *str)
{
	t_param		*param;

	if (*str != '%')
		return (NULL);
	if(!(param = set_put_param()))
		return (NULL);
	str++;
	assisning_param(str, &param);
	if (param->fill == '0' && param->justify == LEFT)
		param->fill = ' ';
	printf("precision : %d\nwidth : %d\njustify : %d\nfill : %d\nspecifier : %d\n", param->precision, param->width, param->justify, param->fill, param->specifier);
	return (param);
}

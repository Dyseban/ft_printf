/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 08:40:53 by thgermai          #+#    #+#             */
/*   Updated: 2020/01/03 15:29:56 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "../libft/libft.h"

# define HEXADECIMAL "0123456789abcdef"
# define VALID_VALUE "cspdiuxX%"
# define VALID_FLAGS "-.0*"
# define LEFT 1
# define RIGHT 0

typedef struct	s_param
{
	int		specifier;
	int		width;
	int		precision;
	int		justify;
	char	fill;
}				t_param;

int				ft_printf(const char *str, ...);
int				next_arg_index(const char *str);
const char		*ft_refresh_str(const char *str);
int				define_type(char c);

t_param			*parsing_param(const char *str, va_list args);

int				pf_fill_char(va_list args, t_param *param);
int				pf_fill_str(va_list args, t_param *param);
int				pf_fill_add(va_list args, t_param *param);
int				pf_fill_deci(va_list args, t_param *param);
int				pf_fill_int(va_list args, t_param *param);
int				pf_fill_unsi(va_list args, t_param *param);
int				pf_fill_hexa(va_list args, t_param *param);
int				pf_fill_hexa_caps(va_list args, t_param *param);
int				pf_fill_modulo(va_list args, t_param *param);

char			*fill_width_left(char *str, t_param *param);
char			*fill_width_right(char *str, t_param *param);
char			*check_width_num(char *str, t_param *param);
char			*check_precision_num(char *str, t_param *param);
char			*fill_precision(char *str, t_param *param);

#endif

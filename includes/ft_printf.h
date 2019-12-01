/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:15:05 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/01 14:24:20 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>

# define HEXADECIMAL "0123456789ABCDEF"
# define VALID_VALUE "cspdiuxX%"

int			ft_printf(const char *str, ...);
int			nb_args(const char *str);
int			next_arg_index(const char *str);
int			ft_define_type(const char *str);

char		*pf_fill_char(va_list args, char *output);
char		*pf_fill_str(va_list args, char *output);
char		*pf_fill_deci(va_list args, char *output);
char		*pf_fill_int(va_list args, char *output);
char		*pf_fill_unsi(va_list args, char *output);
char		*pf_fill_hexa(va_list args, char *output);
char		*pf_fill_HEXA(va_list args, char *output);
char		*pf_fill_modulo(va_list args, char *output);

#endif

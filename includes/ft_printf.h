/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgermain <thomasgermain@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:15:05 by thgermai          #+#    #+#             */
/*   Updated: 2019/11/26 20:10:13 by thomasgerma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "stdarg.h"
# include <stdio.h>

# define HEXADECIMAL "0123456789ABCDEF"

int			ft_printf(const char *str, ...);
int			nb_args(const char *str);
int			next_arg_index(const char *str);
int			ft_define_type(const char *str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:24:41 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/01 17:41:46 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include "libft.h"

int	ft_printf(const char *format, ...);
int	ft_is_format_spec(const char *format, int i);
int	ft_nonposit_conv(const char *format, int *i, va_list &ap1);
int	ft_posit_conv(const char *format, int *i, va_list ap);
int	ft_has_pos_arg(const char *format, int i);
int	ft_has_flags(const char *format, int i);

#endif

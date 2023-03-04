/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 13:45:14 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/04 15:03:45 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_newstr(int prec, int minf, int flag, char *str)
{
	int	memalloc;

	memalloc = (ft_strlen(str) + 1);

}

int	ft_convstr(const char *format, int *i, __va_elem_t *node, va_list ap)
{
	int	cast;
	int	pre;
	int	min;
	int	fl;

	if (format[(*i) - 1] == 37)
	{
		ft_putstr_fd(*(node->__va_arg), 1);
		return (ft_strlen(*(node->__va_arg)));
	}
	if (ft_islengthmod(format[(*i) - 1]))
		cast = ft_check_lengthmod(format, i);
	if ((ft_isdigit(format[(*i) - 1])) || (format[(*i) - 1] == 36))
		pre = ft_check_prec(format, i, ap, node);
	if ((ft_isdigit(format[(*i) - 1])) || (format[(*i) - 1] == 36))
		min = ft_check_min(format, i, ap, node);
	if (ft_isflag(format[(*i) - 1]))
		fl = ft_check_flags(format, i);
	while (!(ft_is_conv_spec(format[(*i)])))
		(*i)++;
	return (ft_printstr(ft_newstr(pre, min, fl, *(node->__va_arg)), i, node));
}

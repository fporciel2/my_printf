/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:12:50 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/02 14:22:44 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_conversion(const char *format, int *i, __va_elem_t *node, va_list ap)
{
	while (!(ft_is_conv_spec(format[(*i)])))
		(*i)++;
	if (format[(*i)] == 99)
		return (ft_convchar(format, i, node, ap));
	else if (format[(*i)] == 115)
		return (ft_convstr(format, i, node, ap));
	else if (format[(*i)] == 112)
		return (ft_convvoid(format, i, node, ap));
	else if (format[(*i)] == 100)
		return (ft_convdec(format, i, node, ap));
	else if (format[(*i)] == 105)
		return (ft_convint(format, i, node, ap));
	else if (format[(*i)] == 117)
		return (ft_convunsdec(format, i, node, ap));
	else if (format[(*i)] == 120)
		return (ft_convlhex(format, i, node, ap));
	else if (format[(*i)] == 88)
		return (ft_convuhex(format, i, node, ap));
}

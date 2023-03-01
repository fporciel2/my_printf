/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:30:55 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/01 15:20:04 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_printf2(const char *format, int result, int *i)
{
	(*i)++;
	if (format[(*i)] == 37)
	{
		write(1, &(format[(*i)]), 1);
		result++;
	}
	return (result);
}

static int	ft_printf1(const char *format, va_list ap, int result, va_list ap1)
{
	int	i;

	i = 0;
	while (format[i] != 0)
	{
		if (format[i] != 37)
		{
			write(1, &(format[i]), 1);
			result++;
			i++;
		}
		else if (ft_is_format_spec(format, i) == 0)
			i++;
		else if (ft_is_format_spec(format, i) == 1)
			result = result + ft_printf2(format, result, &i);
		else if (ft_is_format_spec(format, i) == 2)
			result = result + ft_nonposit_conv(format, &i, &ap1, ap);
		else if (ft_is_format_spec(format, i) == 3)
			result = result + ft_posit_conv(format, &i, ap);
	}
	return (result);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	va_list	ap1;
	int		result;

	if ((format == NULL) || (format[0] == 0))
		return (0);
	va_start(ap, format);
	va_copy(ap1, ap);
	result = 0;
	result = ft_printf1(format, ap, result, ap1);
	va_end(ap1);
	va_end(ap);
	return (result);
}

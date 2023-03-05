/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 13:45:14 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/05 08:20:39 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_printstr1(int memalloc, int *i, __va_elem_t *node, int flag)
{
	int	result;
	int	start;

	result = 0;
	start = 0;
	if (memalloc <= ((int)ft_strlen(*(node->__va_arg)) + 1))
	{
		while (memalloc-- > 0)
		{
			write(1, (*(node->__va_arg))[start], 1);
			start++;
			result++;
		}
	}
	else
	{
		while (memalloc-- > ((int)ft_strlen(*(node->__va_arg)) + 1))
		{
			write(1, " ", 1);
			result++;
		}
		ft_putstr_fd(*(node->__va_arg), 1);
		result = result + (int)ft_strlen(*(node->__va_arg));
	}
	return (result);
}

static int	ft_printstr(int memalloc, int *i, __va_elem_t *node, int flag)
{
	int	result;

	result = 0;
	if ((ft_has_space(flag)) && ((*(node->__va_arg))[0] == 0))
	{
		memalloc++;
		while (result < memalloc)
		{
			write(1, " ", 1);
			result++;
		}
		return (result);
	}
	else
		return (ft_printstr1(memalloc, i, node, flag));
}

static int	ft_newstr(int prec, int minf, char *str)
{
	int	memalloc;

	memalloc = ((int)ft_strlen(str) + 1);
	if ((prec == 0) && (minf == 0))
		memalloc = memalloc;
	else if (minf == 0)
	{
		if (memalloc > prec)
			memalloc = prec;
	}
	else if (minf > memalloc)
		memalloc = minf;
	return (memalloc);
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
		return ((int)ft_strlen(*(node->__va_arg)));
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
	return (ft_printstr(ft_newstr(pre, min, *(node->__va_arg)), i, node, fl));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convvoid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 12:07:04 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/05 16:04:41 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_fl1(int value_len, int min, int fl, __va_elem_t *node)
{
	int	mem;

	mem = 0;
	if (((int)(**(node->__va_arg))) < 0)
	{
		write(1, "-", 1);
		mem++;
	}
	else if ((((int)(**(node->__va_arg))) >= 0) && (ft_has_plus(fl)))
	{
		write(1, "+", 1);
		mem++;
	}
	while ((ft_has_minus(fl)) && (min-- > value_len))
		mem++;
	while ((!(ft_has_minus(fl))) && (min-- > value_len))
	{
		write(1, "0", 1);
		mem++;
	}
	return (mem);
}

static int	ft_fl(int fl, __va_elem_t *node, int min)
{
	int	mem;
	int	value_len;

	mem = 0;
	value_len = ft_value_len(node);
	else if ((ft_has_minus(fl)) && (ft_has_space(fl)))
		mem++;
	while ((ft_has_minus(fl)) && (min-- > value_len))
		mem++;
	if ((!(ft_has_plus(fl))) && (!(ft_has_minus(fl))) && (ft_has_space(fl)))
	{
		write(1, " ", 1);
		mem++;
	}
	mem = mem + ft_fl1(value_len, min, fl);
	return (mem);
}

static int	ft_printvoid(__va_elem_t *node, int mem, int pre, int fl)
{
	int	result;
	int	pre2;

	pre2 = pre;
	result = (mem + ft_putvhex_fd(((int)(**(node->__va_arg))), 1));
	if (pre > 0)
	{
		write(1, ".", 1);
		pre--;
		result++;
	}
	while (pre-- > 0)
	{
		write(1, "0", 1);
		result++;
	}
	while ((pre2 > 0) && (ft_has_minus(fl)) && (mem-- > ft_value_len(node)))
	{
		write(1, "0", 1);
		result++;
	}
	while (ft_has_minus(fl) && (mem-- > ft_value_len(node)) && (result++ >= 0))
		write(1, " ", 1);
	return (result);
}

int	ft_convvoid(const char *format, int *i, __va_elem_t *node, va_list ap)
{
	int	cast;
	int	pre;
	int	min;
	int	fl;

	if (format[(*i) - 1] == 37)
		return (ft_putvhex_fd(((int)(**(node->__va_arg))), 1));
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
	return (ft_printvoid(node, ft_fl(fl, node, min), pre, fl));
}

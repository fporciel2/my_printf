/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_posit_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:26:18 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/03 10:12:33 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static __va_elem_t	*ft_goto_position(__va_elem_t *node, int positional_arg)
{
	while (positional_arg != 1)
	{
		node = node->__va_next;
		positional_arg--;
		if ((node->__va_next) == NULL)
			break ;
	}
	return (node);
}

static int	ft_power(int base, int exp)
{
	int	power;

	power = base;
	if ((base == 0) && (exp != 0))
		return (0);
	if (exp == 0)
		return (1);
	if (exp == 1)
		return (base);
	if (exp == 2)
		return (base * base);
	while (exp > 1)
	{
		power = (power * base);
		exp--;
	}
	return (power);
}

static int	ft_calculate_position(const char *format, int j)
{
	int	length;
	int	num;
	int	exp;

	num = 0;
	length = j;
	while (format[j] != 36)
		j++;
	exp = ((j - length) - 1);
	while (length < j)
	{
		num = num + ((format[length] - 48) * ft_power(10, exp));
		exp--;
		length++;
	}
	return (num);
}

int	ft_posit_conv(const char *format, int *i, va_list ap)
{
	int			j;
	int			result;
	int			positional_arg;
	__va_elem_t	*node;

	j = (*i) + 1;
	node = ap->__ap;
	positional_arg = ft_calculate_position(format, j);
	node = ft_goto_position(node, positional_arg);
	while (format[(*i)] != 36)
		(*i)++;
	(*i)++;
	result = ft_conversion(format, i, node, ap);
	free(node);
	return (result);
}

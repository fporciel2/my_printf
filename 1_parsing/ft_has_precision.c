/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:01:07 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/02 10:28:35 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_has_posit_field(const char *format, int j)
{
	j++;
	if ((!(ft_isdigit(format[j]))) && (format[j] != 36))
		return (0);
	else if (format[j] == 36)
	{
		j++;
		return (ft_has_lengthmod(format, j));
	}
	else
	{
		while (ft_isdigit(format[j]))
			j++;
		if (format[j] == 36)
			return (ft_has_lengthmod(format, j));
		else
			return (0);
	}
}

static int	ft_has_precision2(const char *format, int i)
{
	if ((!(ft_isdigit(format[j]))) && (!(format[j] == 42)))
		return (0);
	else
	{
		if (ft_isdigit(format[j]))
		{
			while (ft_isdigit(format[j]))
				j++;
			return (ft_has_lengthmod(format, j));
		}
		else
			return (ft_has_posit_prec(format, j));
	}
}

static int	ft_has_precision1(const char *format, int j)
{
	if ((!(ft_isdigit(format[j]))) && (!(format[j] == 42)))
		return (ft_has_lengthmod(format, j));
	else
	{
		if (ft_isdigit(format[j]))
		{
			while (ft_isdigit(format[j]))
				j++;
			return (ft_has_lengthmod(format, j));
		}
		else
			return (ft_has_posit_prec(format, j));
	}
}

int	ft_has_precision(const char *format, int i)
{
	int	j;

	j = i;
	if (format[j - 1] != 37)
	{
		if (format[j] != 46)
			return (ft_has_lengthmod(format, j));
		else
		{
			j++;
			return (ft_has_precision1(format, j));
		}
	}
	else
	{
		if (format[j] != 46)
			return (0);
		else
		{
			j++;
			return (ft_has_precision2(format, j));
		}
	}
}

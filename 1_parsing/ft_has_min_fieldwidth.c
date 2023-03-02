/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_min_fieldwidth.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 09:29:16 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/02 09:55:42 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_has_posit_field(const char *format, int j)
{
	j++;
	if ((!(ft_isdigit(format[j]))) && (!(format[j] == 36)))
		return (0);
	else if (format[j] == 36)
	{
		j++;
		return (ft_has_precision(format, j));
	}
	else
	{
		while (ft_isdigit(format[j]))
			j++;
		if (format[j] == 36)
			return (ft_has_precision(format, j));
		else
			return (0);
	}
}

static int	ft_has_min_fieldwidth2(const char *format, int j)
{
	if ((!(ft_isdigit(format[j]))) && (!(format[j] == 42)))
		return (0);
	else
	{
		if (ft_isdigit(format[j]))
		{
			while (ft_isdigit(format[j]))
				j++;
			return (ft_has_precision(format, j));
		}
		else
			return (ft_has_posit_field(format, j));
	}
}

static int	ft_has_min_fieldwidth1(const char *format, int j)
{
	if ((!(ft_isdigit(format[j]))) && (!(format[j] == 42)))
		return (ft_has_precision(format, j));
	else
	{
		if (ft_isdigit(format[j]))
		{
			while (ft_isdigit(format[j]))
				j++;
			return (ft_has_precision(format, j));
		}
		else
			return (ft_has_posit_field(format, j));
	}
}

int	ft_has_min_fieldwidth(const char *format, int i)
{
	int	j;

	j = i;
	if (format[j - 1] != 37)
		return (ft_has_min_fieldwidth1(format, j));
	else
		return (ft_has_min_fieldwidth2(format, j));
}

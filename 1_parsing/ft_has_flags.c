/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:44:38 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/02 09:19:31 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_has_flags2(const char *format, int j)
{
	if (!(ft_isflag(format[j])))
		return (0);
	else
	{
		while (ft_isflag(format[j]))
			j++;
		return (ft_has_min_fieldwidth(format, j));
	}
}

int	ft_has_flags(const char *format, int i)
{
	int	j;

	j = i;
	if (format[j - 1] != 37)
	{
		if (!(ft_isflag(format[j])))
			return (ft_has_min_fieldwidth(format, j));
		else
		{
			while (ft_isflag(format[j]))
				j++;
			return (ft_has_min_fieldwidth(format, j));
		}
	}
	else
		return (ft_has_flags2(format[j]));
}

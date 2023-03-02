/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_lengthmod.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:31:17 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/02 10:44:16 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_has_lengthmod2(const char *format, int j)
{
	if (!(ft_islengthmod(format[j])))
		return (0);
	else
	{
		while (ft_islengthmod(format[j]))
			j++;
		return (ft_is_conv_spec(format[j]));
	}
}

int	ft_has_lengthmod(const char *format, int i)
{
	int	j;

	j = i;
	if (format[j - 1] != 37)
	{
		if (!(ft_islengthmod(format[j])))
			return (ft_is_conv_spec(format[j]));
		else
		{
			while (ft_islengthmod(format[j]))
				j++;
			return (ft_is_conv_spec(format[j]))
		}
	}
	else
		return (ft_has_lengthmod2(format, j));
}

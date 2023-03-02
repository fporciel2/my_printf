/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_format_spec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:56:46 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/01 17:57:13 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_is_format_spec(const char *format, int i)
{
	i++;
	if (format[i] == 37)
		return (1);
	else if (ft_has_pos_arg(format, i))
		return (3);
	else if (ft_has_flags(format, i))
		return (2);
	else if (ft_has_min_fieldwidth(format, i))
		return (2);
	else if (ft_has_precision(format, i))
		return (2);
	else if (ft_has_lengthmod(format, i))
		return (2);
	else if (ft_is_conv_spec(format[i]))
		return (2);
	else
		return (0);
}

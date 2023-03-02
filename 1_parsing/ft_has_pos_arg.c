/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_pos_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:17:29 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/02 15:48:33 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_has_pos_arg(const char *format, int i)
{
	int	j;

	j = i;
	if (!(ft_isdigit(format[j])))
		return (0);
	else
	{
		while (ft_isdigit(format[j]))
			j++;
		if (format[j] == 36)
		{
			i++;
			return (ft_has_flags(format, j));
		}
		else
			return (0);
	}
}

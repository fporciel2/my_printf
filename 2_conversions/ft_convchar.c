/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:14:54 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/03 11:35:25 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_convchar(const char *format, int *i, __va_elem_t *node, va_list ap)
{
	int	casting;

	if (format[(*i) - 1] == 37)
	{
		write(1, (node->__va_arg), 1);
		return (1);
	}
	if (ft_islengthmod(format[(*i) - 1]))
		casting = ft_check_lengthmod(format, i);
}

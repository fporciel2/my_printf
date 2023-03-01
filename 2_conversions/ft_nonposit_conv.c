/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nonposit_conv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:24:25 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/01 11:45:35 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_nonposit_conv(const char *format, int *i, va_list ap1)
{
	int	result;

	result = 0;
	result = ft_conversion(format, i, ap1);
	return (result);
}

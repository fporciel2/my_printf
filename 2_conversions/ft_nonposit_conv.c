/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nonposit_conv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:24:25 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/01 15:20:57 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_nonposit_conv(const char *format, int *i, va_list *ap1, va_list ap)
{
	int			j;
	int			result;
	__va_elem_t	*node;

	j = 0;
	result = 0;
	node = (*ap1).__ap;
	result = ft_conversion(format, i, node);
	(*ap1).__ap = node->__va_next;
	free(node);
	return (result);
}

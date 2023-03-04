/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nonposit_conv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:24:25 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/04 07:46:37 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_nonposit_conv(const char *format, int *i, va_list *ap1, va_list ap)
{
	int			result;
	__va_elem_t	*node;

	node = (*ap1)->__ap;
	(*i)++;
	result = ft_conversion(format, i, node, ap);
	(*ap1)->__ap = node->__va_next;
	free(node);
	(*i)++;
	return (result);
}

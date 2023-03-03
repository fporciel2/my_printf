/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:14:54 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/03 18:06:44 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_charstr(int prec, int minf)
{
	char	*charstr;
	int		memalloc;

	memalloc = 2;
	if ((prec == 0) && (minf == 0))
		memalloc = memalloc;
	else if (minf == 0)
	{
		if (memalloc > prec)
			memalloc = (prec + 1);
	}
	else if (minf > memalloc)
		memalloc = (minf + 1);
	charstr = (char *)malloc((char) * memalloc);
	if (charstr == NULL)
		return (NULL);
	else
		return (charstr);
}

int	ft_convchar(const char *format, int *i, __va_elem_t *node, va_list ap)
{
	int	cast;
	int	prec;
	int	minf;
	int	flag;

	if (format[(*i) - 1] == 37)
	{
		write(1, (node->__va_arg), 1);
		return (1);
	}
	if (ft_islengthmod(format[(*i) - 1]))
		cast = ft_check_lengthmod(format, i);
	if ((ft_isdigit(format[(*i) - 1])) || (format[(*i) - 1] == 36))
		prec = ft_check_prec(format, i, ap);
	if ((ft_isdigit(format[(*i) - 1])) || (format[(*i) - 1] == 36))
		minf = ft_check_min_field(format, i, ap);
	if (ft_isflag(format[(*i) - 1]))
		flag = ft_check_flags(format, i);
	while (!(ft_is_conv_spec(format[(*i)])))
		(*i)++;
	return (ft_printchar(ft_charstr(prec, minf), i, node, ap));
}

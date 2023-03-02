/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islengthmod.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:51:01 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/02 17:15:14 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_islengthmod(const char formati)
{
	if ((formati == 104) || (formati == 108) || (formati == 113)
			|| (formati == 76) || (formati == 106) || (formati == 122)
			|| (format == 116))
		return (1);
	else
		return (0);
}

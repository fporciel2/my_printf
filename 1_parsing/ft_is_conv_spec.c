/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_conv_spec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:49:32 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/02 10:54:47 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_is_conv_spec(const char formati)
{
	if ((formati == 99) || (formati == 115) || (formati == 112)
			|| (formati == 100) || (formati == 105) || (formati == 117)
			|| (formati == 120) || (formati == 88))
		return (1);
	else
		return (0);
}

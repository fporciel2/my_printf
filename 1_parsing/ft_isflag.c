/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:33:53 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/02 16:48:13 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_isflag(const char formati)
{
	if ((formati == 35) || (formati == 48) || (formati == 45)
			|| (formati == 32) || (formati == 43))
		return (1);
	else
		return (0);
}

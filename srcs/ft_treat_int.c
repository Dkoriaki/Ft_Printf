/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoriaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 13:31:54 by dkoriaki          #+#    #+#             */
/*   Updated: 2020/02/25 13:15:28 by dkoriaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_treat_int(va_list p_info)
{
	int	c;
	int	written_c;

	written_c = 0;
	c = va_arg(p_info, int);
	written_c += ft_putnbr(c);
	return (written_c);
}

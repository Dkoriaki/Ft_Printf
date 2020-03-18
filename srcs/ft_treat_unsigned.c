/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoriaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:17:31 by dkoriaki          #+#    #+#             */
/*   Updated: 2020/02/26 14:32:20 by dkoriaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_putnbr_unsigned(unsigned long long nb)
{
	static int len;

	if (nb > 9)
	{
		ft_putnbr_unsigned(nb / 10);
		ft_putnbr_unsigned(nb % 10);
	}
	if (nb < 10)
	{
		ft_putchar(nb + 48);
		len++;
	}
	return (len);
}

int		ft_treat_unsigned(va_list p_info)
{
	int						written_c;
	unsigned long long int nb;

	written_c = 0;
	nb = va_arg(p_info, unsigned long long int);
	written_c += ft_putnbr_unsigned(nb);
	return (written_c);
}

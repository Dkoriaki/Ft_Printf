/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoriaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 13:34:08 by dkoriaki          #+#    #+#             */
/*   Updated: 2020/02/26 14:20:40 by dkoriaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_putnbr_hexa(long long nb, char c)
{
	char		*base_x;
	char		*base_X;
	static int	len;
	int			m;

	m = 0;
	if (c == 'x')
		m = 1;
	base_x = "0123456789abcdef";
	base_X = "0123456789ABCDEF";

	if (nb < 0)
		nb = 4294967295 + nb + 1;
	if (nb > 15)
	{
		ft_putnbr_hexa(nb / 16, c);
		ft_putnbr_hexa(nb % 16, c);
	}
	if (nb < 16)
	{
		(m) ? ft_putchar(base_x[nb]) : ft_putchar(base_X[nb]);
		len++;
	}
	return (len);
}

int		ft_treat_hexa(va_list p_info, char c)
{
	unsigned long long	nb;
	int written_c;

	written_c = 0;
	nb = va_arg(p_info, long long int);
	written_c += ft_putnbr_hexa(nb, c);
	return (written_c);
}
	

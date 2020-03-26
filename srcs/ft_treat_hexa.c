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

int		ft_treat_hexa_flags(unsigned long long nb, t_flags *flag, int len_nb ,char c)
{
	int	written_c;
	int	save_p_v;

	written_c = 0;
	save_p_v = flag->p_value;
	if (flag->precision && flag->width)
		flag->zero = 0;
	if (nb < 0)
		flag->width--;
	if (flag->minus)
	{
		while (flag->p_value > len_nb)
		{
			if (nb < 0)
			{
				written_c += ft_putchar('-');
				nb = -nb;
			}
			written_c += ft_putchar('0');
			flag->p_value--;
		}
		written_c += ft_putnbr_hexa(nb, c);
		while (flag->width > save_p_v && flag->width > len_nb)
		{
			written_c += (flag->zero) ? ft_putchar('0') : ft_putchar(' ');
			flag->width--;
		}
	}
	if (!flag->minus)
	{
		while (flag->width > flag->p_value && flag->width > len_nb)
		{
			if (nb < 0 && !flag->precision)
			{
				written_c += ft_putchar('-');
				nb = -nb;
			}
			written_c += (flag->zero) ? ft_putchar('0') : ft_putchar(' ');
			flag->width--;
		}
		while (flag->p_value > len_nb)
		{
			if (nb < 0)
			{
				written_c += ft_putchar('-');
				nb = -nb;
			}
			written_c += ft_putchar('0');
			flag->p_value--;
		}
		written_c += ft_putnbr_hexa(nb, c);
	}
	return (written_c);
}

int		ft_treat_hexa(va_list p_info, char c, t_flags *flag)
{
	unsigned long long	nb;
	int written_c;
	int	len_nb;

	written_c = 0;
	nb = va_arg(p_info, long long int);
	len_nb = ft_nbrlen(nb, 16);
	written_c += ft_treat_hexa_flags(nb, flag, len_nb, c);
	return (written_c);
}
	

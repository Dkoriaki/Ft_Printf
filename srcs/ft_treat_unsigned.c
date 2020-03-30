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

int		ft_putnbr_unsigned(long long nb)
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

int		ft_treat_unsigned_flags(unsigned long nb, t_flags *flag, int len_nb)
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
			written_c += ft_putchar('0');
			flag->p_value--;
		}
		written_c += ft_putnbr_unsigned(nb);
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
		written_c += ft_putnbr_unsigned(nb);
	}
	return (written_c);
}

int		ft_treat_unsigned(va_list p_info, t_flags *flag)
{
	int						written_c;
	unsigned long nb;
	int len_nb;

	written_c = 0;
	nb = va_arg(p_info, unsigned long int);
	len_nb = ft_nbrlen(nb, 10);
	written_c += ft_treat_unsigned_flags(nb, flag, len_nb);
	return (written_c);
}

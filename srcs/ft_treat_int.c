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

int		ft_treat_int_flags(int nb, t_flags *flag, int len_nb)
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
		written_c += ft_putnbr(nb);
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
		written_c += ft_putnbr(nb);
	}
	return (written_c);
}

int		ft_treat_int(va_list p_info, t_flags *flag)
{
	long int	nb;
	int		written_c;
	int		len_nb;

	written_c = 0;
	nb = va_arg(p_info, int);
	len_nb = ft_nbrlen(nb, 10);
	written_c += ft_treat_int_flags(nb, flag, len_nb);
	return (written_c);
}

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

void		ft_putnbr_unsigned(long long nb, t_flags *flag, int len_nb)
{
	if (nb == 0 && flag->precision && len_nb == 0)
		return ;
	if (nb > 9)
	{
		ft_putnbr_unsigned(nb / 10, flag, len_nb);
		ft_putnbr_unsigned(nb % 10, flag, len_nb);
	}
	if (nb < 10)
		ft_putchar(nb + 48);
}

int			ft_unsigned_minus(unsigned long nb, t_flags *flag, int len_nb)
{
	int	written_c;
	int	save_p;

	written_c = 0;
	save_p = flag->p_value;
	while (flag->p_value > len_nb)
	{
		written_c += ft_putchar('0');
		flag->p_value--;
	}
	written_c += len_nb;
	ft_putnbr_unsigned(nb, flag, len_nb);
	while (flag->width > save_p && flag->width > len_nb)
	{
		written_c += (flag->zero) ? ft_putchar('0') : ft_putchar(' ');
		flag->width--;
	}
	return (written_c);
}

int			ft_unsigned_flags(unsigned long nb, t_flags *flag, int len_nb)
{
	int	written_c;
	int	save_p;

	written_c = 0;
	save_p = flag->p_value;
	while (flag->width > save_p && flag->width > len_nb)
	{
		written_c += (flag->zero) ? ft_putchar('0') : ft_putchar(' ');
		flag->width--;
	}
	while (flag->p_value > len_nb)
	{
		written_c += ft_putchar('0');
		flag->p_value--;
	}
	written_c += len_nb;
	ft_putnbr_unsigned(nb, flag, len_nb);
	return (written_c);
}

int			ft_treat_unsigned(va_list p_info, t_flags *flag)
{
	int				written_c;
	unsigned long	nb;
	int				len_nb;

	written_c = 0;
	nb = va_arg(p_info, unsigned long int);
	len_nb = ft_nbrlen(nb, 10, flag);
	if ((flag->precision && flag->width) || (flag->minus && flag->zero))
		flag->zero = 0;
	if (flag->minus)
		written_c += ft_unsigned_minus(nb, flag, len_nb);
	if (!flag->minus)
		written_c += ft_unsigned_flags(nb, flag, len_nb);
	return (written_c);
}

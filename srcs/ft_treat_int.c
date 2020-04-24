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

int		ft_treat_int_minus(int nb, t_flags *flag, int len_nb)
{
	int	written_c;
	int	save_p;

	written_c = 0;
	save_p = flag->p_value;
	(nb < 0 && save_p >= len_nb) ? flag->width-- : flag->width;
	while (flag->p_value > len_nb || (nb < 0 && flag->p_value == len_nb))
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -nb;
			flag->p_value++;
		}
		written_c += ft_putchar('0');
		flag->p_value--;
	}
	written_c += len_nb;
	ft_putnbr(nb, flag, len_nb);
	while (flag->width > save_p && flag->width > len_nb)
	{
		written_c += (flag->zero) ? ft_putchar('0') : ft_putchar(' ');
		flag->width--;
	}
	return (written_c);
}

int		ft_treat_int_flags(int nb, t_flags *flag, int len_nb)
{
	int	written_c;
	int	save_p;

	written_c = 0;
	save_p = flag->p_value;
	(nb < 0 && save_p >= len_nb) ? flag->width-- : flag->width;
	while (flag->width > save_p && flag->width > len_nb)
	{
		written_c += (flag->zero) ? ft_putchar('0') : ft_putchar(' ');
		flag->width--;
	}
	while (flag->p_value > len_nb || (nb < 0 && flag->p_value == len_nb))
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -nb;
			flag->p_value++;
		}
		written_c += ft_putchar('0');
		flag->p_value--;
	}
	written_c += len_nb;
	ft_putnbr(nb, flag, len_nb);
	return (written_c);
}

int		ft_treat_int(va_list p_info, t_flags *flag)
{
	long int	nb;
	int			written_c;
	int			len_nb;

	written_c = 0;
	nb = va_arg(p_info, int);
	len_nb = ft_nbrlen(nb, 10, flag);
	if ((flag->precision && flag->width) || (flag->minus && flag->zero))
		flag->zero = 0;
	if (flag->width && flag->zero && nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (flag->minus)
		written_c += ft_treat_int_minus(nb, flag, len_nb);
	if (!flag->minus)
		written_c += ft_treat_int_flags(nb, flag, len_nb);
	return (written_c);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoriaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:55:14 by dkoriaki          #+#    #+#             */
/*   Updated: 2020/02/26 17:18:49 by dkoriaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_pointer_len(unsigned long nb, t_flags *flag)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (flag->precision) ? 0 : 1;
	while (nb)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

void	ft_putnbr_p(unsigned long nb, t_flags *flag, int len)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb == 0 && flag->precision && len == 0)
		return ;
	if (nb > 15)
	{
		ft_putnbr_p(nb / 16, flag, len);
		ft_putnbr_p(nb % 16, flag, len);
	}
	if (nb < 16)
		ft_putchar(base[nb]);
}

int		ft_pointer_minus(unsigned long nb, t_flags *flag, int len_nb)
{
	int	save_p;
	int	written_c;

	save_p = flag->p_value;
	written_c = 0;
	written_c += ft_putstr("0x");
	while (flag->p_value > len_nb)
	{
		written_c += ft_putchar('0');
		flag->p_value--;
	}
	written_c += len_nb;
	ft_putnbr_p(nb, flag, len_nb);
	while (flag->width > save_p && flag->width > len_nb)
	{
		written_c += (flag->zero) ? ft_putchar('0') : ft_putchar(' ');
		flag->width--;
	}
	return (written_c);
}

int		ft_pointer_flags(unsigned long nb, t_flags *flag, int len_nb)
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
	written_c += ft_putstr("0x");
	while (flag->p_value > len_nb)
	{
		written_c += ft_putchar('0');
		flag->p_value--;
	}
	written_c += len_nb;
	ft_putnbr_p(nb, flag, len_nb);
	return (written_c);
}

int		ft_treat_pointer(va_list p_info, t_flags *flag)
{
	int				written_c;
	unsigned long	nb;
	int				len_nb;

	written_c = 0;
	flag->width -= 2;
	nb = va_arg(p_info, unsigned long int);
	len_nb = ft_pointer_len(nb, flag);
	if ((flag->precision && flag->width) || (flag->minus && flag->zero))
		flag->zero = 0;
	if (!flag->minus)
		written_c += ft_pointer_flags(nb, flag, len_nb);
	if (flag->minus)
		written_c += ft_pointer_minus(nb, flag, len_nb);
	return (written_c);
}

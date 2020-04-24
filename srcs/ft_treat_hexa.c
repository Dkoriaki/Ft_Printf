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

void	ft_putnbr_h(unsigned long nb, char c, t_flags *flag, int len)
{
	char		*base_1;
	char		*base_2;
	int			m;

	m = 0;
	if (nb == 0 && flag->precision && len == 0)
		return ;
	if (c == 'x')
		m = 1;
	base_1 = "0123456789abcdef";
	base_2 = "0123456789ABCDEF";
	if (nb > 15)
	{
		ft_putnbr_h(nb / 16, c, flag, len);
		ft_putnbr_h(nb % 16, c, flag, len);
	}
	if (nb < 16)
		(m) ? ft_putchar(base_1[nb]) : ft_putchar(base_2[nb]);
}

int		ft_hexa_flags(unsigned long nb, t_flags *flag, int len, char c)
{
	int	written_c;
	int	save_p;

	written_c = 0;
	save_p = flag->p_value;
	while (flag->width > save_p && flag->width > len)
	{
		written_c += (flag->zero) ? ft_putchar('0') : ft_putchar(' ');
		flag->width--;
	}
	while (flag->p_value > len)
	{
		written_c += ft_putchar('0');
		flag->p_value--;
	}
	written_c += len;
	ft_putnbr_h(nb, c, flag, len);
	return (written_c);
}

int		ft_hexa_minus(unsigned long nb, t_flags *flag, int len, char c)
{
	int	save_p;
	int	written_c;

	save_p = flag->p_value;
	written_c = 0;
	while (flag->p_value > len)
	{
		written_c += ft_putchar('0');
		flag->p_value--;
	}
	written_c += len;
	ft_putnbr_h(nb, c, flag, len);
	while (flag->width > save_p && flag->width > len)
	{
		written_c += (flag->zero) ? ft_putchar('0') : ft_putchar(' ');
		flag->width--;
	}
	return (written_c);
}

int		ft_treat_hexa(va_list p_info, char c, t_flags *flag)
{
	unsigned int	nb;
	int				written_c;
	int				len_nb;

	written_c = 0;
	nb = va_arg(p_info, unsigned int);
	len_nb = ft_nbrlen(nb, 16, flag);
	if ((flag->precision && flag->width) || (flag->minus && flag->zero))
		flag->zero = 0;
	if (flag->minus)
		written_c += ft_hexa_minus(nb, flag, len_nb, c);
	else
		written_c += ft_hexa_flags(nb, flag, len_nb, c);
	return (written_c);
}

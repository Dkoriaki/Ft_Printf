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

int		ft_putnbr_pointer(unsigned long long pointer)
{
	static int	len;
	char		*base;
	
	base = "0123456789abcdef";
	if (pointer > 15)
	{
		ft_putnbr_pointer(pointer / 16);
		ft_putnbr_pointer(pointer % 16);
	}
	if (pointer < 16)
	{
		ft_putchar(base[pointer]);
		len++;
	}
	//printf("len = %d\n", len);
	return (len);
}

int		ft_treat_pointer_flags(unsigned long long nb, t_flags *flag, int len_nb)
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
		written_c += ft_putnbr_pointer(nb);
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
			written_c += ft_putchar('0');
			flag->p_value--;
		}
		written_c += ft_putnbr_pointer(nb);
	}
	return (written_c);
}

int		ft_treat_pointer(va_list p_info, t_flags *flag)
{
	int						written_c;
	unsigned long long	pointer;
	int			len_nb;

	written_c = 0;
	written_c += ft_putstr("0x");
	flag->width -= 2;
	pointer = va_arg(p_info, unsigned long long int);
	len_nb = ft_nbrlen(pointer, 16);
	written_c += ft_treat_pointer_flags(pointer, flag, len_nb);
	return (written_c);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoriaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:32:40 by dkoriaki          #+#    #+#             */
/*   Updated: 2020/02/26 14:43:46 by dkoriaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_treat_percent_flag(t_flags *flag)
{
	int	written_c;

	written_c = 0;
	if ((flag->precision && flag->width) || (flag->minus && flag->zero))
		flag->zero = 0;
	if (flag->minus)
		written_c += ft_putchar('%');
	while (flag->width > 1)
	{
		written_c += (flag->zero) ? ft_putchar('0') : ft_putchar(' ');
		flag->width--;
	}
	if (!flag->minus)
		written_c += ft_putchar('%');
	return (written_c);
}

int		ft_treat_percent(t_flags *flag)
{
	int		written_c;

	written_c = 0;
	written_c += ft_treat_percent_flag(flag);
	return (written_c);
}

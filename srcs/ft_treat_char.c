/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoriaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 13:33:31 by dkoriaki          #+#    #+#             */
/*   Updated: 2020/02/26 17:03:38 by dkoriaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_treat_char_flag(t_flags *flag, char c)
{
	int	written_c;

	written_c = 0;
	if (flag->minus)
		written_c += ft_putchar(c);
	while (flag->width > 1)
	{
		written_c += ft_putchar(' ');
		flag->width--;
	}
	if (!flag->minus)
		written_c += ft_putchar(c);
	return (written_c);
}

int		ft_treat_char(va_list p_info, t_flags *flag)
{
	int	written_c;
	int	c;

	written_c = 0;
	c = va_arg(p_info, int);
	written_c += ft_treat_char_flag(flag, c);
	return (written_c);
}

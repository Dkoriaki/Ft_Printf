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

int		ft_putnbr_pointer(unsigned long long int pointer)
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
	return (len);
}

int		ft_treat_pointer(va_list p_info)
{
	int						written_c;
	unsigned long long int	pointer;

	//written_c += ft_putstr("0x");
	pointer = va_arg(p_info, unsigned long long int);
	written_c += ft_putnbr_pointer(pointer);
	printf("written_c = %d", written_c);
	return (written_c);
}

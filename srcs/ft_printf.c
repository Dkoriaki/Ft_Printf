/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoriaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 11:03:18 by dkoriaki          #+#    #+#             */
/*   Updated: 2020/02/26 17:10:09 by dkoriaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_printf(const char *str, ...)
{
	va_list		p_info;
	int			written_c;

	va_start(p_info, str);
	written_c = 0;
	written_c += ft_check_str(str, p_info);
	return (written_c);
}

int		main(void)
{
	//ft_printf("%-5%|\n%2%");
	//printf("Vrai = %d", printf("%-5c\n", 'D'));
	//printf("moi  = %d", ft_printf("%-5c\n", 'D'));
	ft_printf("%-20s|", "yo les kheys");
	return (0);
}

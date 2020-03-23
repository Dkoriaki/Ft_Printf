/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoriaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:29:54 by dkoriaki          #+#    #+#             */
/*   Updated: 2020/02/26 16:03:19 by dkoriaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_check_conv(char c)
{
	char	*all_conv;
	int		i;

	all_conv = "cspdiuxX%";
	i = 0;
	while (all_conv[i])
	{
		if (c == all_conv[i])
			return (1);
		i++;
	}
	return (0);
}

t_flags	ft_init_flag(void)
{
	t_flags	flag;

	flag.precision = 0;
	flag.width = 0;
	flag.zero = 0;
	flag.minus = 0;
	return (flag);
}

int		ft_check_str(const char *str, va_list p_info)
{
	t_flags flag;
	int		i;
	int		written_c;

	i = 0;
	written_c = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar(str[i]);
			written_c++;
		}
		else
		{
			flag = ft_init_flag();
			written_c += ft_check_param(&str[i++], p_info, &flag);
			while (ft_check_conv(str[i]) == 0)
				i++;
		}
		i++;
	}
	return (written_c);
}

int		ft_check_param(const char *str, va_list p_info, t_flags *flag)
{
	int	i;
	int	written_c;

	i = 1;
	written_c = 0;
	ft_treat_flags(flag, str, p_info);
	while (ft_check_conv(str[i]) == 0)
		i++;
	flag->flag = str[i];
	if (flag->flag == 's')
		written_c += ft_treat_str(p_info, flag);
	if (flag->flag == 'c')
		written_c += ft_treat_char(p_info, flag);
	if (flag->flag == 'd' || flag->flag == 'i')
		written_c += ft_treat_int(p_info, flag);
	//if (flag->flag == 'x' || flag->flag == 'X')
	//	written_c += ft_treat_hexa(p_info, flag->flag);
	//if (flag->flag == 'u')
	//	written_c += ft_treat_unsigned(p_info);
	if (flag->flag == '%')
		written_c += ft_treat_percent(flag);
	//if (flag->flag == 'p')
	//	written_c += ft_treat_pointer(p_info);
	return (written_c);
}

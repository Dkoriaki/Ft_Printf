/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoriaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:50:08 by dkoriaki          #+#    #+#             */
/*   Updated: 2020/02/21 17:03:41 by dkoriaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_strlen(char *str, t_flags *flag)
{
	int	i;

	i = 0;
	if (str && flag)
	{
		while (str[i])
			i++;
		if (flag->precision && flag->p_value < i)
			return(flag->p_value);
	}
	return (i);
}

int		ft_putstr_len(char *str, int p_len, int str_len)
{
	int	i;

	i = 0;
	if (p_len > str_len)
		p_len = str_len;
	while (i < p_len && str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (p_len);
}

int		ft_treat_str_minus(t_flags *flag, char *str, int str_len)
{
	int	written_c;

	written_c = 0;
	if (flag->precision)
		written_c += ft_putstr_len(str, flag->p_value, str_len);
	else
		written_c += ft_putstr(str);
	while (flag->width > str_len)
	{
		written_c += ft_putchar(' ');
		flag->width--;
	}
	return (written_c);
}


int		ft_treat_str_flag(t_flags *flag, char *str)
{
	int	written_c;
	int	str_len;

	written_c = 0;
	str_len = ft_strlen(str, flag);
	if (flag->minus)
		ft_treat_str_minus(flag, str, str_len);
	if (!flag->minus)
	{
		while (flag->width > str_len)
		{
			written_c += ft_putchar(' ');
			flag->width--;
		}
		if (flag->precision)
			written_c += ft_putstr_len(str, flag->p_value, str_len);
		else
			written_c += ft_putstr(str);
	}
	return(written_c);
}

int		ft_treat_str(va_list p_info, t_flags *flag)
{
	char	*string;
	int		written_c;

	written_c = 0;
	string = va_arg(p_info, char *);
	if (!string)
		string = "(null)";
	written_c = ft_treat_str_flag(flag, string);
	return (written_c);
}

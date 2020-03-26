/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoriaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:00:46 by dkoriaki          #+#    #+#             */
/*   Updated: 2020/02/25 14:27:56 by dkoriaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		ft_treat_flags_first(t_flags *flag, const char *str, va_list p_info)
{
	int	i;

	i = 1;
	while (ft_check_conv(str[i]) == 0 && str[i])
	{
		if (str[i] == '*' && flag->precision != 1)
			flag->width = va_arg(p_info, int);
		if ((str[i] >= '1' && str[i] <= '9') && flag->precision != 1)
		{
			flag->width = ft_width(&str[i]);
			i += ft_nbrlen(flag->width, 10);
		}

		if (str[i] == '-')
			flag->minus = 1;
		if (str[i] == '0')
			flag->zero = 1;
		if (str[i] == '.')
			flag->precision = 1;
		i++;
	}
}

void		ft_treat_flags(t_flags *flag,const char *str, va_list p_info)
{
	int		i;

	i = 1;
	ft_treat_flags_first(flag, str, p_info);
	while (ft_check_conv(str[i]) == 0 && str[i])
	{
		if (str[i] == '*' && flag->precision == 1)
			flag->p_value = va_arg(p_info, int);
		if ((str[i] >= '0' && str[i] <= '9') && flag->precision == 1)
		{
			flag->p_value = ft_width(&str[i]);
			i += ft_nbrlen(flag->p_value, 10);
		}
		i++;
	}
}

int		ft_width(const char *str)
{
	char	*result;
	int		len;
	int		i;
	int		number;

	len = 0;
	i = 0;
	while (str[len] >= '0' && str[len] <= '9')
		len++;
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	while (i < len)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	number = ft_atoi(result);
	free(result);
	return (number);
}


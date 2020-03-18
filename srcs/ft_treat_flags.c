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

void		ft_treat_flags(t_flags *flag,const char *str, va_list p_info)
{
	int		i;

	i = 1;
	while (ft_check_conv(str[i]) == 0)
	{
		if (str[i] == '*' && flag->precision != 1)
			flag->width = va_arg(p_info, int);
		if ((str[i] >= '1' && str[i] <= '9') && flag->precision != 1)
		{
			flag->width = ft_width(&str[i]);
			i += ft_nbrlen(flag->width);
		}
		if (str[i] == '*' && flag->precision == 1)
			flag->precision_value = va_arg(p_info, int);
		if ((str[i] >= '1' && str[i] <= '9') && flag->precision == 1)
		{
			flag->precision_value = ft_width(&str[i]);
			i += ft_nbrlen(flag->precision_value);
		}
		if (str[i] == '0')
			flag->zero = 1;
		if (str[i] == '.')
			flag->precision = 1;
		if (str[i] == '-')
			flag->minus = 1;
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
	//printf("\nstr = |%s|\n", str);
	while (str[len] >= '0' && str[len] <= '9')
		len++;
	//printf("\nlen = %d\n", len);
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	while (i < len)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	//printf("\nresult = %s\n", result);
	//printf("\nresult = %s\n", result);
	number = ft_atoi(result);
	free(result);
	//printf("\nnumber is : %d\n", number);
	return (number);
}


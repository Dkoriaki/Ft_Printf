/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoriaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:15:35 by dkoriaki          #+#    #+#             */
/*   Updated: 2020/02/26 17:03:29 by dkoriaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_atoi(const char *str)
{
	int i;
	int negatif;
	int nb;

	i = 0;
	negatif = 1;
	nb = 0;
	while ((str[i] == ' ') || (str[i] == '\f') || (str[i] == '\n') ||
			(str[i] == '\r') || (str[i] == '\t') || (str[i] == '\v'))
		i++;
	while ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			negatif *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	return (nb * negatif);
}

int		ft_nbrlen(long int nb, int base, t_flags *flag)
{
	unsigned long		nui;
	int					i;

	i = 0;
	if (nb == 0 && (flag->precision))
		return (0);
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nui = -nb;
		i++;
	}
	else
		nui = nb;
	while (nui)
	{
		nui /= base;
		i++;
	}
	return (i);
}

int		ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

void	ft_putnbr(int nb, t_flags *flag, int len_nb)
{
	long int	nbr;

	nbr = nb;
	if (nbr == 0 && flag->precision && len_nb == 0)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10, flag, len_nb);
		ft_putnbr(nbr % 10, flag, len_nb);
	}
	else
		ft_putchar(nbr + 48);
}

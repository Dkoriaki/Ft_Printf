/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoriaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 10:31:11 by dkoriaki          #+#    #+#             */
/*   Updated: 2020/02/26 17:04:13 by dkoriaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_flags
{
	char		flag;
	int			precision;
	int			p_value;
	int			w_here;
	int			width;
	int			zero;
	int			minus;
}				t_flags;

int				ft_putchar(char c);
int				ft_putstr(char *str);
int				ft_atoi(const char *str);
int				ft_nbrlen(long int nb, int base, t_flags *flag);
void			ft_putnbr(int nb, t_flags *flag, int len_nb);
char			*ft_itoa(long long int nb);
int				ft_width(const char *str);
int				ft_strlen(char *str, t_flags *flag);

int				ft_printf(const char *str, ...);
int				ft_check_str(const char *str, va_list p_info);
int				ft_check_conv(char c);
int				ft_check_param(const char *str, va_list p_info, t_flags *flag);

t_flags			ft_init_flag(void);

void			ft_treat_flags(t_flags *flag, const char *str, va_list p_info);
void			ft_treatflags_2(t_flags *flag, const char *str, va_list p_info);

int				ft_treat_str(va_list p_info, t_flags *flag);
int				ft_treat_str_flag(t_flags *flag, char *str);
int				ft_treat_str_minus(t_flags *flag, char *str, int str_len);
int				ft_putstr_len(char *str, int p_len, int str_len);

int				ft_treat_char(va_list p_info, t_flags *flag);
int				ft_treat_char_flag(t_flags *flag, char c);

int				ft_treat_int(va_list p_info, t_flags *flag);
int				ft_treat_int_flags(int nb, t_flags *flag, int len_nb);
int				ft_treat_int_minus(int nb, t_flags *flag, int len_nb);

int				ft_treat_hexa(va_list p_info, char c, t_flags *flag);
int				ft_hexa_flags(unsigned long nb, t_flags *flag, int len, char c);
int				ft_hexa_minus(unsigned long nb, t_flags *flag, int len, char c);
void			ft_putnbr_h(unsigned long nb, char c, t_flags *flag, int len);

int				ft_treat_unsigned(va_list p_info, t_flags *flag);
int				ft_unsigned_flags(unsigned long nb, t_flags *flag, int len_nb);
int				ft_unsigned_minus(unsigned long nb, t_flags *flag, int len_nb);
void			ft_putnbr_unsigned(long long nb, t_flags *flag, int len_nb);

int				ft_treat_percent(t_flags *flag);
int				ft_treat_percent_flag(t_flags *flag);

int				ft_pointer_len(unsigned long nb, t_flags *flag);
void			ft_putnbr_p(unsigned long pointer, t_flags *flag, int len);
int				ft_pointer_flags(unsigned long nb, t_flags *flag, int len_nb);
int				ft_pointer_minus(unsigned long nb, t_flags *flag, int len_nb);
int				ft_treat_pointer(va_list p_info, t_flags *flag);

#endif

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
//                  UTILS                 //

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_atoi(const char *str);
int		ft_nbrlen(int nb);
int		ft_putnbr(int nb);
int		ft_width(const char *str);   //Dans la fonction "ft_treat_flags"
int		ft_strlen(char *str);        // dans treat_str

//                  Creation de la structure Flag              //

typedef struct	s_flags
{
	char	flag;
	int		precision;
	int		precision_value;
	int		width;
	int		zero;
	int		minus;
}				t_flags;

//                  Fonctions Principales          //

int		ft_printf(const char *str, ...);
int		ft_check_str(const char *str, va_list p_info);
int		ft_check_conv(char c);
int		ft_check_param(const char *str, va_list p_info, t_flags *flag);

//                   Init flag                    //

t_flags		ft_init_flag(void);

//		     Treat Flag              //

void		ft_treat_flags(t_flags *flag, const char *str, va_list p_info);

//		     Treat str        //

int		ft_treat_str(va_list p_info, t_flags *flag);
int		ft_treat_str_flag(t_flags *flag, char *str);
int		ft_putstr_len(char *str, int len);

//		     Treat char        //

int		ft_treat_char(va_list p_info, t_flags *flag);
int		ft_treat_char_flag(t_flags *flag, char c);

//		     Treat int         //

//		     Treat hexa        //

//		     Treat unsigned int      //

//		     Treat percent      //

int		ft_treat_percent(t_flags *flag);
int		ft_treat_percent_flag(t_flags *flag);

//		     Treat pointer       //


int		ft_treat_int(va_list p_info);
int		ft_putnbr_hexa(long long nb, char c);
int		ft_treat_hexa(va_list p_info, char c);
int		ft_putnbr_unsigned(unsigned long long nb);
int		ft_treat_unsigned(va_list p_info);
int		ft_putnbr_pointer(unsigned long long pointer);
int		ft_treat_pointer(va_list p_info);

#endif

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

//                  Creation de la structure Flag              //

typedef struct	s_flags
{
	char	flag;
	int		precision;
	int		p_value;
	int		width;
	int		zero;
	int		minus;
}				t_flags;

//                  UTILS                 //

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_atoi(const char *str);
int		ft_nbrlen(long long int nb, int base);
int		ft_putnbr(int nb);
int		ft_width(const char *str);   //Dans la fonction "ft_treat_flags"
int		ft_strlen(char *str, t_flags *flag);        // dans treat_str

//                  Fonctions Principales          //

int		ft_printf(const char *str, ...);
int		ft_check_str(const char *str, va_list p_info);
int		ft_check_conv(char c);
int		ft_check_param(const char *str, va_list p_info, t_flags *flag);

//                   Init flag                    //

t_flags		ft_init_flag(void);

//		     Treat Flag              //

void		ft_treat_flags(t_flags *flag, const char *str, va_list p_info);
void		ft_treat_flags_first(t_flags *flag, const char *str, va_list p_info); // Pour gagner des lignes

//		     Treat str        //

int		ft_treat_str(va_list p_info, t_flags *flag);
int		ft_treat_str_flag(t_flags *flag, char *str);
int		ft_putstr_len(char *str, int len);

//		     Treat char        //

int		ft_treat_char(va_list p_info, t_flags *flag);
int		ft_treat_char_flag(t_flags *flag, char c);

//		     Treat int         //

int		ft_treat_int(va_list p_info, t_flags *flag);
int		ft_treat_int_flags(int nb, t_flags *flag, int len_nb);

//		     Treat hexa        //

int		ft_treat_hexa(va_list p_info, char c, t_flags *flag);
int		ft_treat_hexa_flags(unsigned long long nb, t_flags *flag, int len_nb, char c);
//		     Treat unsigned int      //

int		ft_treat_unsigned(va_list p_info, t_flags *flag);
int		ft_treat_unsigned_flags(unsigned long long nb, t_flags *flag, int len_nb);
int		ft_putnbr_unsigned(long long nb);

//		     Treat percent      //

int		ft_treat_percent(t_flags *flag);
int		ft_treat_percent_flag(t_flags *flag);

//		     Treat pointer       //


int		ft_putnbr_pointer(unsigned long long pointer);
int		ft_treat_pointer_flags(unsigned long long nb, t_flags *flag, int len_nb);
int		ft_treat_pointer(va_list p_info, t_flags *flag);

#endif

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkoriaki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/16 10:21:52 by dkoriaki          #+#    #+#              #
#    Updated: 2020/02/16 11:58:00 by dkoriaki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC		=	./includes/libftprintf.h

NAME	=	libftprintf.a

SRCS	=	./srcs/ft_putchar.c \
			./srcs/ft_printf.c \
			./srcs/ft_check_param.c \

HEADER	=	./includes/libftprintf.h

OBJS	= ${SRCS:.c=.o}

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

AR		= ar rc

.c.o:
			${CC} ${CFLAGS} -c $< -I $(HEADER) -o ${<:.c=.o}

all:		${NAME}

$(NAME):	${OBJS} ${INC}
			${AR} ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		clean fclean re all

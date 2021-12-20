# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 15:41:17 by yichoi            #+#    #+#              #
#    Updated: 2021/12/13 16:18:52 by yichoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

AR			= ar
ARFLAGS		= rcs

RM			= rm
RMFLAGS		= -f

INCLUDES	= ./libftprintf.h

SRCS		= ft_printf.c	\
				ft_format_specifier.c	\
				ft_write_character.c	\
				ft_write_string.c		\
				ft_write_integer.c	\
				ft_write_decimal.c	\
				ft_write_unsigned.c	\
				ft_format_specifier.c	\
				ft_write_address.c	\
				ft_write_lower_hex.c	\
				ft_write_upper_hex.c	\
				ft_strlen.c				\

SRCS_BN		=

OBJS		= $(SRCS:.c=.o)

OBJS_BONUS	= $(SRCS_BN:.c=.o)

ifdef WITH_BONUS
A_OBJS = $(OBJS) $(OBJS_BONUS)
else
A_OBJS = $(OBJS)
endif

.PHONY : all
all : $(NAME)

%.o : %.c $(INCLUDES)
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(A_OBJS)
		$(AR) $(ARFLAGS) $@ $^

.PHONY : clean
clean :
		$(RM) $(RMFLAGS) $(OBJS) $(OBJS_BONUS)

.PHONY : fclean
fclean : clean
		$(RM) $(RMFLAGS) $(NAME)

.PHONY : re
re :
		$(MAKE) fclean
		$(MAKE) caller
.PHONY : bonus
bonus :
		$(MAKE) WITH_BONUS=1 all

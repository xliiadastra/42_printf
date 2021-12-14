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

INCLUDES	= ./libft.h

SRCS		= 

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



# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 15:55:25 by jnoh              #+#    #+#              #
#    Updated: 2022/09/23 01:00:09 by jnoh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Werror -Wextra
SRCS		= main.c utils.c utils_stack.c \
			sort.c sort_utils.c get_input.c sort_utils2.c \
			operation_push.c operation_rotate.c operation_rrotate.c operation_swap.c 
BONUS_SRCS	= bonus/checker_doop_bonus.c bonus/checker_bonus.c \
			  bonus/get_input_bonus.c bonus/operation_push_bonus.c \
			  bonus/operation_swap_bonus.c bonus/operation_rotate_bonus.c \
			  bonus/operation_rrotate_bonus.c bonus/utils_stack_bonus.c \
			  bonus/utils_bonus.c

OBJS		= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)
LIBFT		= libft/libft.a
NAME		= push_swap
BONUS_NAME	= checker
RM 			= rm -f
HEADERS		= ./push_swap.h ./libft/libft.h
BONUS_HEADER= ./push_swap_bonus.h ./libft/libft.h

define libft_call
		cd libft && $(MAKE) $(1) && cd ..
endef

all	: $(NAME)

bonus: $(BONUS_OBJS) $(BONUS_HEADERS)
	$(call libft_call, all)
	$(CC) -o $(BONUS_NAME) $(CFLAGS) $(BONUS_OBJS) -L ./libft -lft

$(NAME) : $(OBJS) $(HEADERS)
	$(call libft_call, all)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) -L ./libft -lft

clean:
	cd libft && make clean && cd ..
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean:
	cd libft && make fclean && cd ..
	$(RM) $(OBJS) $(BONUS_OBJS)
	$(RM) $(NAME) $(BONUS_NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re

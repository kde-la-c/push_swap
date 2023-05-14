# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kde-la-c <kde-la-c@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 14:34:32 by kde-la-c          #+#    #+#              #
#    Updated: 2023/05/07 14:34:42 by kde-la-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
SRC			= push_swap.c
OBJS		= $(SRC:%.c=%.o)
INCLUDE		= push_swap.h
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm
RFLAGS		= -f

LIBNAME		= libft.a
LIBPATH		= libft/

all:		$(NAME)

$(NAME):	$(OBJS) $(INCLUDE) $(LIBNAME)
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBNAME)
			@echo "\033[0;32m--- push_swap compiled successfully! ---\033[0m"

l:			$(OBJS) $(INCLUDE) $(LIBNAME)
			@$(CC) $(CFLAGS) -fsanitize=leak -g3 $(OBJS) -o $(NAME) $(LIBNAME)
			@echo "\033[0;32m--- push_swap compiled successfully! ---\033[0m"

m:			$(OBJS) $(INCLUDE) $(LIBNAME)
			@$(CC) $(CFLAGS) -fsanitize=address -g3 $(OBJS) -o $(NAME) $(LIBNAME)
			@echo "\033[0;32m--- push_swap compiled successfully! ---\033[0m"

$(LIBNAME):
			$(MAKE) -C $(LIBPATH)
			cp $(LIBPATH)$(LIBNAME) .
			$(MAKE) -C $(LIBPATH) fclean

clean:
			$(RM) $(RFLAGS) $(OBJS)
			@echo "\033[0;32m--- Objects cleaned successfully! ---\033[0m"

fclean:		clean
			$(RM) $(RFLAGS) $(NAME) $(LIBNAME)
			@echo "\033[0;32m--- Archive cleaned successfully! ---\033[0m"

re:			fclean all

.PHONY:		all clean fclean re

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
NAME_DBG	= dbg
SRC			= push_swap.c\
			read_args.c\
			get_ordinals.c\
			operations.c\
			operation.c\
			sort.c\
			sort_5.c\
			sort_more.c\
			get_info.c\
			output.c\
			sort_more_utils.c\
			\
			test_utils.c
OBJS		= $(SRC:%.c=%.o)
INCLUDE		= push_swap.h
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm
RFLAGS		= -rf

LIBNAME		= libft.a
LIBPATH		= libft/

all:		$(NAME)

$(NAME):	$(OBJS) $(INCLUDE) $(LIBNAME)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBNAME)
			@echo "\033[0;32m--- push_swap compiled successfully! ---\033[0m"

l:			$(OBJS) $(INCLUDE) $(LIBNAME)
			$(CC) $(CFLAGS) -fsanitize=leak -g3 $(OBJS) -o $(NAME) $(LIBNAME)
			$(RM) $(RFLAGS) $(OBJS)
			@echo "\033[0;32m--- push_swap compiled successfully! ---\033[0m"

m:			$(OBJS) $(INCLUDE) $(LIBNAME)
			$(CC) $(CFLAGS) -fsanitize=address -g3 $(OBJS) -o $(NAME) $(LIBNAME)
			$(RM) $(RFLAGS) $(OBJS)
			@echo "\033[0;32m--- push_swap compiled successfully! ---\033[0m"

debug:		$(NAME_DBG)

$(NAME_DBG): $(LIBNAME) $(SRC)
			$(CC) $(CFLAGS) -fdiagnostics-color=always -g3 $(SRC) $(LIBNAME) -o $@

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

.PHONY:		all clean fclean re debug l m

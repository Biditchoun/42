# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swijnber <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/02 17:17:59 by swijnber          #+#    #+#              #
#    Updated: 2022/06/02 18:30:42 by swijnber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_printf.c\
				printfing.c\
				printf_chars.c\
				printf_nb.c\
				utilities.c
OBJS		=	${SRCS:.c=.o}
NAME		=	libftprintf.a
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
INCLUDES	=	-I./ -I./Libft

%.o:	%.c
				${CC} ${CFLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}

${NAME}:		${OBJS}
				make -C Libft 
				cp Libft/libft.a .
				ar -rcs $@ $^

all:			${NAME}

clean:
				rm -f ${OBJS}
				make clean -C Libft

fclean:			clean
				rm -f ${NAME}
				make fclean -C Libft

re:				fclean
				${MAKE}

.PHONY:			all clean fclean re

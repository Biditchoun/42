# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swijnber <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 05:21:22 by swijnber          #+#    #+#              #
#    Updated: 2022/10/13 17:42:07 by swijnber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	push_swap.c init_stack_1.c init_stack_2.c\
				instructions_1.c instructions_2.c\
				algorithms_hq.c algorithm_1.c\
				brute_force_1.c brute_force_2.c brute_force_3.c
				
OBJS		=	${SRCS:.c=.o}
NAME		=	push_swap.a
PNAME		=	push_swap
LIBFT		=	libft.a
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
INCLUDES	=	-I./ -I./Libft

%.o:	%.c
				${CC} ${CFLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}

${NAME}:		${OBJS}
				make -C Libft 
				cp Libft/${LIBFT} ${NAME}
				ar -rcs $@ $^
				${CC} ${CFLAGS} ${NAME} -o ${PNAME}

all:			${NAME}

bonus:			${NAME}

clean:
				rm -f ${OBJS}
				make clean -C Libft

fclean:			clean
				rm -f ${NAME} ${PNAME}
				make fclean -C Libft

re:				fclean
				${MAKE}

.PHONY:			all bonus clean fclean re

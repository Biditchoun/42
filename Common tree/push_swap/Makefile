SRCS		=	push_swap.c init_stack.c init_stack2.c \
				instructions_1.c instructions_2.c utils.c
				
OBJS		=	${SRCS:.c=.o}
NAME		=	push_swap.a
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

all:			${NAME}

bonus:			${NAME}

clean:
				rm -f ${OBJS}
				make clean -C Libft

fclean:			clean
				rm -f ${NAME}
				make fclean -C Libft

re:				fclean
				${MAKE}

.PHONY:			all bonus clean fclean re
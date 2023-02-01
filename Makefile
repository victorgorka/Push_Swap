# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 18:51:04 by vde-prad          #+#    #+#              #
#    Updated: 2023/02/01 18:18:21 by vde-prad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS	= 	push_swap.c \
			first_check.c \
			atoll.c

OBJS	= ${SRCS:.c=.o}
NAME	= push_swap
LIBRARY = libft/libft.a
CC		= gcc -g
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

################# RULES #####################

all: lib comp
	
lib:
	@echo "\nCOMPILING LIBFT"
	@${MAKE} -C ./libft

comp: ${NAME}

$(NAME): ${OBJS}
	@echo "\nCOMPILING PUSH SWAP"
	@${CC} ${CFLAGS} ${OBJS} ${LIBRARY} -o ${NAME}
	@echo "\nFINISHED"

clean:
	@echo "CLEANED"
	@${MAKE} -C ./libft clean
	@${RM} ${OBJS}

fclean: clean
	@${MAKE} -C ./libft fclean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

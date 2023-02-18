# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 18:51:04 by vde-prad          #+#    #+#              #
#    Updated: 2023/02/18 20:45:49 by vde-prad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 	push_swap.c \
			first_check.c \
			init_stack.c \
			push.c \
			swap.c \
			rotate.c \
			revrotate.c \
			small_sort.c \
			sorting.c \
			target_pos.c \
			utils.c \
			cost.c \
			cheap_moves.c

SRCS_BN =	bonus/checker.c \
			first_check.c \
			init_stack.c \
			bonus/push.c \
			bonus/revrotate.c \
			bonus/rotate.c \
			bonus/swap.c \
			utils.c \
			target_pos.c \
			bonus/ft_lstadd_back_bonus.c \
			bonus/ft_lstlast_bonus.c \
			bonus/ft_lstnew_bonus.c \
			bonus/ft_lstclear_bonus.c \
			bonus/ft_lstdelone_bonus.c
			
OBJS_BN = ${SRCS_BN:.c=.o}
OBJS	= ${SRCS:.c=.o}
NAME	= push_swap
NAME_CK = checker
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

bonus: all ${NAME_CK}

${NAME_CK}: ${OBJS_BN}
	@echo "\nCOMPILING CHECKER"
	@${CC} ${CFLAGS} ${OBJS_BN} ${LIBRARY} -o ${NAME_CK}

clean:
	@echo "CLEANED"
	@${MAKE} -C ./libft clean
	@${RM} ${OBJS}
	@${RM} ${OBJS_BN}

fclean: clean
	@${MAKE} -C ./libft fclean
	@${RM} ${NAME}
	@${RM} ${NAME_CK}

re: fclean all

.PHONY: all clean fclean re

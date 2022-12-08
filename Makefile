# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clacaill <clacaill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 19:06:52 by clacaill          #+#    #+#              #
#    Updated: 2022/12/07 18:41:13 by clacaill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libftprintf.a
SRC		= ft_printf.c

OBJS		= ${SRC:.c=.o}
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
				$(MAKE) all -C libft
				cp libft/libft.a $(NAME)
				ar -rcs ${NAME} ${OBJS}

all:    ${NAME}

clean:
		$(MAKE) clean -C ./libft
		${RM} ${OBJS}

fclean:    clean
		$(MAKE) fclean -C ./libft
		${RM} ${NAME}
        
re:     fclean $(NAME)

.PHONY: all clean fclean re
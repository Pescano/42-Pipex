# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paescano <paescano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 19:15:19 by paescano          #+#    #+#              #
#    Updated: 2022/12/03 19:15:25 by paescano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = pipex

SRCS = ft_split.c pipex_error.c pipex.c pipex_utils.c

OBJS = $(SRCS:.c=.o)

HEADER = pipex.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

AR = ar -src

all: ${NAME}

$(NAME): $(OBJS)
	${AR} ${NAME}.a ${OBJS}
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	${RM} ${OBJS} ${NAME}.a

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
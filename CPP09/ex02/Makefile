# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 17:21:22 by thibaud           #+#    #+#              #
#    Updated: 2024/10/16 16:11:11 by tmouche          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := main.cpp PmergeMe.cpp
HDRS := PmergeMe.class.hpp
OBJS := $(SRCS:.c=.o)
CFLAGS := -g -Wall -Wextra -Werror -std=c++98
CC := c++
NAME := pmergeme

all: $(NAME)

%.o: %.c 
	${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(OBJS) Makefile $(HDRS)
	${CC} ${CFLAGS} $(OBJS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f *.o

re: fclean all

.PHONY: all clean fclean re

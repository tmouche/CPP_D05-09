# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 17:21:22 by thibaud           #+#    #+#              #
#    Updated: 2024/10/10 20:31:56 by thibaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := main.cpp BitcoinExchange.cpp
HDRS := BitcoinExchange.class.hpp
OBJS := $(SRCS:.c=.o)
CFLAGS := -g #-Wall -Wextra -Werror -std=c++98
CC := c++
NAME := btc

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

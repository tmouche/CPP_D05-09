# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 17:21:22 by thibaud           #+#    #+#              #
#    Updated: 2024/09/24 11:40:43 by tmouche          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := main.cpp
HDRS := Easyfind.template.hpp
OBJS := $(SRCS:.c=.o)
CFLAGS := -Wall -Wextra -Werror -std=c++98
CC := c++
NAME := Easyfind

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

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 17:21:22 by thibaud           #+#    #+#              #
#    Updated: 2024/09/18 10:29:52 by thibaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := main.cpp
HDRS := whatever.template.hpp
OBJS := $(SRCS:.c=.o)
CFLAGS := -Wall -Wextra -Werror -std=c++98
CC := c++
NAME := Template

all: $(NAME)

%.o: %.c 
	${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(OBJS) Makefile $(HDRS)
	${CC} $(OBJS) -o $(NAME)

clean:
	rm -f $(NAME) Home_shrubbery

fclean: clean
	rm -f *.o

re: fclean all

.PHONY: all clean fclean re

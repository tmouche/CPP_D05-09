# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 17:21:22 by thibaud           #+#    #+#              #
#    Updated: 2024/09/09 20:21:24 by thibaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := main.cpp Bureaucrat.cpp
HDRS := Bureaucrat.class.hpp
OBJS := $(SRCS:.c=.o)
CFLAGS := -Wall -Wextra -Werror
CC := c++
NAME := Bureaucrat

all: $(NAME)

%.o: %.c 
	${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(OBJS) Makefile $(HDRS)
	${CC} $(OBJS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f *.o

re: fclean all

.PHONY: all clean fclean re

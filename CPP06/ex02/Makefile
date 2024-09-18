# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 17:21:22 by thibaud           #+#    #+#              #
#    Updated: 2024/09/18 06:10:36 by thibaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := main.cpp
HDRS := Base.class.hpp A.class.hpp B.class.hpp C.class.hpp
OBJS := $(SRCS:.c=.o)
CFLAGS := -Wall -Wextra -Werror -std=c++98
CC := c++
NAME := Identify

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

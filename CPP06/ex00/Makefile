# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 17:21:22 by thibaud           #+#    #+#              #
#    Updated: 2024/09/17 06:58:19 by thibaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := main.cpp ScalarConverter.cpp CharConverter.cpp IntConverter.cpp FloatConverter.cpp DoubleConverter.cpp
HDRS := ScalarConverter.class.hpp CharConverter.class.hpp IntConverter.class.hpp FloatConverter.class.hpp DoubleConverter.class.hpp
OBJS := $(SRCS:.c=.o)
CFLAGS := -Wall -Wextra -Werror
CC := c++
NAME := ScalarConverter

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

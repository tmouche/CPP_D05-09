# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 17:21:22 by thibaud           #+#    #+#              #
#    Updated: 2024/11/14 14:35:34 by tmouche          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := main.cpp ScalarConverter.cpp CharConverter.cpp IntConverter.cpp FloatConverter.cpp DoubleConverter.cpp
HDRS := ScalarConverter.class.hpp CharConverter.class.hpp IntConverter.class.hpp FloatConverter.class.hpp DoubleConverter.class.hpp
OBJS := $(SRCS:.cpp=.o)
CFLAGS := -Wall -Wextra -Werror -std=c++98
CC := c++
NAME := ScalarConverter

all: $(NAME)

%.o: %.cpp 
	${CC}  -c $< -o $@

$(NAME): $(OBJS) Makefile $(HDRS)
	${CC} $(OBJS) -o $(NAME)

clean:
	rm -f $(NAME) Home_shrubbery

fclean: clean
	rm -f *.o

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 17:21:22 by thibaud           #+#    #+#              #
#    Updated: 2024/11/22 16:26:11 by tmouche          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := main.cpp ScalarConverter.cpp CharConverter.cpp DoubleConverter.cpp FloatConverter.cpp IntConverter.cpp
HDRS := ScalarConverter.class.hpp CharConverter.class.hpp DoubleConverter.class.hpp FloatConverter.class.hpp IntConverter.class.hpp

OBJS_D := OBJS/
OBJS := $(SRCS:%.cpp=$(OBJS_D)%.o)

CFLAGS := -Wall -Wextra -Werror -std=c++98
CC := c++
NAME := Converter

all: $(NAME)

$(NAME): $(OBJS_D) $(OBJS)
	${CC} $(OBJS) -o $(NAME)

$(OBJS_D)%.o: %.cpp $(HDRS) Makefile
	${CC} ${CFLAGS} -c $< -o $@

$(OBJS_D):
	@mkdir -p $(OBJS_D)

clean:
	rm -f $(NAME)

fclean: clean
	rm -rf $(OBJS_D)

re: fclean all

.PHONY: all clean fclean re

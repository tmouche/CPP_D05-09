# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 17:21:22 by thibaud           #+#    #+#              #
#    Updated: 2024/11/22 17:06:02 by tmouche          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := main.cpp
HDRS := Easyfind.template.hpp

OBJS_D := OBJS/
OBJS := $(SRCS:%.cpp=$(OBJS_D)%.o)

CFLAGS := -Wall -Wextra -Werror -std=c++98
CC := c++
NAME := Easyfind

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

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 17:21:22 by thibaud           #+#    #+#              #
#    Updated: 2024/11/14 13:11:04 by tmouche          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := main.cpp Bureaucrat.cpp Form.cpp
HDRS := Bureaucrat.class.hpp Form.class.hpp

OBJS_D := OBJS/
OBJS := $(SRCS:%.cpp=$(OBJS_D)%.o)

CFLAGS := -Wall -Wextra -Werror
CC := c++
NAME := Bureaucrat

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

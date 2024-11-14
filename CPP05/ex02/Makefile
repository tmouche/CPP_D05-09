# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 17:21:22 by thibaud           #+#    #+#              #
#    Updated: 2024/11/14 13:46:47 by tmouche          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
HDRS := Bureaucrat.class.hpp AForm.class.hpp PresidentialPardonForm.class.hpp RobotomyRequestForm.class.hpp ShrubberyCreationForm.class.hpp

OBJS_D := OBJS/
OBJS := $(SRCS:%.cpp=$(OBJS_D)%.o)

CFLAGS := -Wall -Wextra -Werror
CC := c++
NAME := BureaucratForm

all: $(NAME)

$(NAME): $(OBJS)
	${CC} $(OBJS) -o $(NAME)

$(OBJS_D)%.o: %.cpp $(HDRS) Makefile
	${CC} ${CFLAGS} -c $< -o $@

$(OBJS_D):
	@mkdir -p $(OBJS_D)

clean:
	rm -f $(NAME) $(DEPS)

fclean: clean
	rm -rf $(OBJS_D)

re: fclean all

.PHONY: all clean fclean re
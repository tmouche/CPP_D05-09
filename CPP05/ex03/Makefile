# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 17:21:22 by thibaud           #+#    #+#              #
#    Updated: 2024/09/11 18:38:05 by thibaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp
HDRS := Bureaucrat.class.hpp AForm.class.hpp PresidentialPardonForm.class.hpp RobotomyRequestForm.class.hpp ShrubberyCreationForm.class.hpp Intern.class.hpp
OBJS := $(SRCS:.c=.o)
CFLAGS := -Wall -Wextra -Werror
CC := c++
NAME := BureaucratIntern

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

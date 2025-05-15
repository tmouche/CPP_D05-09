# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 17:21:22 by thibaud           #+#    #+#              #
#    Updated: 2025/05/15 13:21:02 by thibaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= btc

HEADER		=	hdrs/
SRCS_DIR	=	srcs/
OBJS_DIR	=	.objs/
DEPS_DIR	=	.deps/
SRCS		=	main.cpp BitcoinExchange.cpp RateDate.cpp

OBJS		= $(SRCS:%.cpp=$(OBJS_DIR)%.o)
DEPS		= $(SRCS:%.cpp=$(DEPS_DIR)%.d)

CXX		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -g3 -I $(HEADER)
DFLAGS	= -MMD -MP -MT $@ -MF $(DEPS_DIR)$*.d
RM		= rm -rf

-include $(DEPS)

.DEFAULT_GOAL = all

all: $(NAME) 

run: all
	./$(NAME)

$(NAME): $(OBJS) Makefile
	@$(CXX) $(CFLAGS) -o $(NAME) $(OBJS) && echo "$(NAME) compilation completed !!!"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
$(DEPS_DIR):
	@mkdir -p $(DEPS_DIR)

$(OBJS): $(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp | $(OBJS_DIR) $(DEPS_DIR)
	@$(CXX) $(CFLAGS) $(DFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS_DIR) $(DEPS_DIR) && echo "Objects cleared..."

fclean: clean
	@$(RM) $(NAME) && echo "Fully cleared..."

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re run

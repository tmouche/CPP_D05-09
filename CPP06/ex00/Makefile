# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 17:21:22 by thibaud           #+#    #+#              #
#    Updated: 2025/03/20 11:08:30 by thibaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ScalarConvertion

HEADER		=	hdrs/
SRCS_DIR	=	srcs/
OBJS_DIR	=	.objs/
DEPS_DIR	=	.deps/
SRCS		=	main.cpp CharConverter.cpp DoubleConverter.cpp FloatConverter.cpp IntConverter.cpp ScalarConverter.cpp


OBJS		= $(SRCS:%.cpp=$(OBJS_DIR)%.o)
DEPS		= $(SRCS:%.cpp=$(DEPS_DIR)%.d)

CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -g3 -I $(HEADER)
DFLAGS	= -MMD -MP -MT $@ -MF $(DEPS_DIR)$*.d
RM		= rm -rf

-include $(DEPS)

.DEFAULT_GOAL = all

all: $(NAME)

run: all
	./$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) && echo "$(END)$(GREEN)\n* $(NAME) compilation completed !!!\n$(END)"

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)
$(DEPS_DIR):
	mkdir -p $(DEPS_DIR)

$(OBJS): $(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp | $(OBJS_DIR) $(DEPS_DIR)
	$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@ && echo "  $@" 

clean:
		$(RM) $(OBJS_DIR) $(DEPS_DIR) && echo "$(RED) * object cleared...$(END)"

fclean: clean
		$(RM) $(NAME) && $(RM) $(DIR_BUILD) $(OBJS_DIR) $(DEPS_DIR) && echo "$(RED) * $(NAME) is fully cleared...$(END)"

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re

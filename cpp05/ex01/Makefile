# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skapersk <skapersk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/11 15:03:40 by skapersk          #+#    #+#              #
#    Updated: 2024/08/26 16:58:29 by skapersk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex01

CC = c++

INCLUDES = includes/

CFLAGS = -Wall -Werror -Wextra -std=c++98 -I $(INCLUDES)

SRC_DIR = sources/

OBJ_DIR = objects/

SRC = main.cpp \
	  Bureaucrat.cpp \
	  Form.cpp \

OBJ = $(SRC:.cpp=.o)

SRC_FILES = $(addprefix $(SRC_DIR), $(SRC))

OBJ_FILES = $(addprefix $(OBJ_DIR), $(OBJ))

.PHONY : all clean fclean re

all : $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME) : $(OBJ_FILES)
	@$(CC) $(OBJ_FILES) -o $(NAME)

clean :
	@$(RM) -rf $(OBJ_DIR)

fclean :
	@$(RM) -rf $(OBJ_DIR)
	@$(RM) $(NAME)

re :
	@make fclean --no-print-directory
	@make all --no-print-directory

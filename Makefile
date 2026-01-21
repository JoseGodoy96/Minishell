# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aarias-d <aarias-d@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/12 13:04:48 by jgodoy-m          #+#    #+#              #
#    Updated: 2026/01/21 21:32:13 by aarias-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Minishell file name
NAME = minishell

# Compiler and compilation flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR) -I$(LIBFT_DIR)/include -I$(GNL_DIR)/include -g
MAKEFLAGS += --no-print-directory

# Define directories
INCLUDE_DIR = ./include
SRC_DIR = ./src
LIBFT_DIR = ./libft
GNL_DIR = ./gnl
PARSER = /parser
EXECUTOR = /executor
UTILS = /utils
BUILTINS = /builtins
ENV = /env


# Source files and object files
SRC = 	$(SRC_DIR)/main.c \
		$(SRC_DIR)$(BUILTINS)/builtins.c \
		$(SRC_DIR)$(BUILTINS)/cd.c \
		$(SRC_DIR)$(BUILTINS)/env.c \
		$(SRC_DIR)$(BUILTINS)/echo.c \
		$(SRC_DIR)$(BUILTINS)/pwd.c \
		$(SRC_DIR)$(EXECUTOR)/execute.c \
		$(SRC_DIR)$(EXECUTOR)/exec_single.c \
		$(SRC_DIR)$(EXECUTOR)/path_utils.c \
		$(SRC_DIR)$(ENV)/env_utils.c \
		$(SRC_DIR)$(PARSER)/lexer_utils_1.c \
		$(SRC_DIR)$(PARSER)/lexer_utils_2.c \
		$(SRC_DIR)$(PARSER)/lexer_utils_3.c \
		$(SRC_DIR)$(PARSER)/lexer.c \
		$(SRC_DIR)$(UTILS)/free.c 

OBJ = $(SRC:.c=.o)

# Libraries
LIBFT = $(LIBFT_DIR)/libft
GNL_LIB = $(GNL_DIR)/gnl

# Create libraries and delete files
AR = ar rcs
RM = rm -f

# Indicates that the following rules are not real files
.PHONY: all clean fclean re 

# Rule that compiles everything by default
all: $(NAME)

# Rule to create the minishell
$(NAME): $(LIBFT) $(GNL_LIB) $(OBJ)
	@echo "⚠️	compilando...	⚠️"
	@$(CC) $(CFLAGS) $(OBJ) $(GNL_LIB) $(LIBFT) -o $(NAME)
	@echo "✅	!!compilado!!	✅"

# Rule to build libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Rule to build gnl (expects gnl/Makefile to produce libgnl.a)
$(GNL_LIB):
	@$(MAKE) -C $(GNL_DIR)

# Convert .c files to .o
%.o: %.c $(INCLUDE_DIR)/minishell.h
	@$(CC) $(CFLAGS) -c $< -o $@


# Rule to delete all created object files
clean:
	@echo "🚮	Limpiado...	🚮"
	@$(RM) $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(GNL_DIR) clean
	@echo "✅	!Limpio!	✅"

# Delete all .o and .a files
fclean: clean
	@$(RM) $(NAME) $(LIBFT) $(GNL_LIB)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(GNL_DIR) fclean

re: fclean all

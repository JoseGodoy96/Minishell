# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aarias-d <aarias-d@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/12 13:04:48 by jgodoy-m          #+#    #+#              #
#    Updated: 2026/01/16 23:06:30 by aarias-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library file name
NAME = minishell

# Compiler and compilation flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR) -I$(LIBFT_DIR)/include -I$(GNL_DIR)/include -g

# Define directories
INCLUDE_DIR = ./include
SRC_DIR = ./src
LIBFT_DIR = ./libft
GNL_DIR = ./gnl

# Source files and object files
SRC = 	$(SRC_DIR)/main.c 

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

# Rule to create the fdf
$(NAME): $(LIBFT) $(GNL_LIB) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(GNL_LIB) $(LIBFT) -o $(NAME)

# Rule to build libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Rule to build gnl (expects gnl/Makefile to produce libgnl.a)
$(GNL_LIB):
	$(MAKE) -C $(GNL_DIR)

# Convert .c files to .o
%.o: %.c $(INCLUDE_DIR)/fdf.h
	$(CC) $(CFLAGS) -c $< -o $@


# Rule to delete all created object files
clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean

# Delete all .o and .a files
fclean: clean
	$(RM) $(NAME) $(LIBFT) $(GNL_LIB)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean

re: fclean all

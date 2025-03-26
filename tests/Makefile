# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lagea < lagea@student.s19.be >             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/01 10:00:00 by lagea             #+#    #+#              #
#    Updated: 2025/03/26 22:51:03 by lagea            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
ORANGE=\033[38;2;255;165;0m
RED=\033[0;31m
NC=\033[0m

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
LIBFT_DIR = ../
TEST_DIR = ./

# Source files
TEST_FILES = test_main.c test_original.c test_double_linked_list.c test_printf.c test_added_funct.c test_get_next_line.c

# Object files
OBJ_FILES = $(TEST_FILES:.c=.o)

# Target
TEST_EXEC = run_tests

# Rules
all: $(TEST_EXEC)

$(TEST_EXEC): $(OBJ_FILES) $(LIBFT_DIR)lib/libft.a
	@echo "$(BLUE)Building test executable...$(NC)"
	@$(CC) $(CFLAGS) -o $@ $(OBJ_FILES) -L$(LIBFT_DIR)lib -lft
	@echo "$(GREEN)Test executable built. Run with ./$(TEST_EXEC)$(NC)"

%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

$(LIBFT_DIR)lib/libft.a:
	@echo "$(YELLOW)Building libft...$(NC)"
	@make -C $(LIBFT_DIR)

clean:
	@echo "$(ORANGE)Cleaning test objects...$(NC)"
	@rm -f $(OBJ_FILES)

fclean: clean
	@echo "$(RED)Removing test executable...$(NC)"
	@rm -f $(TEST_EXEC)

re: fclean all

.PHONY: all clean fclean re

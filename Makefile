# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 17:32:01 by jolandestee       #+#    #+#              #
#    Updated: 2023/10/18 09:41:14 by jolandestee      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable file / name
NAME = push_swap

# Compiling and CFLAGS
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories 
LIBFT_DIR = libft
SRCS_DIR = srcs

# Source files 
SRCS_SRCS = $(wildcard $(SRCS_DIR)/*.c)
LIBFT_SRCS = $(wildcard $(LIBFT_DIR)/*.c)

# Object files 
SRCS_OBJS = $(SRCS_SRCS:.c=.o)
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRCS_OBJS) $(LIBFT_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(SRC_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT_DIR)/%.o: $(LIBFT_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(SRCS_OBJS) $(LIBFT_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
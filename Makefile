# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/29 13:57:32 by barmarti          #+#    #+#              #
#    Updated: 2025/06/29 16:26:54 by barmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#                                 CONFIGURATION                                #
# **************************************************************************** #

NAME_SERVER	= server
NAME_CLIENT	= client

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -ggdb
RM			= rm -f
MKDIR		= mkdir -p

# ----------------------------------------------------------------------------- #
# Directories
# ----------------------------------------------------------------------------- #

SRC_DIR		= .
OBJ_DIR		= obj
LIBFT_DIR	= libft
INCLUDE_DIRS = include libft libft/ft_printf libft/ft_printf/src libft/ft_printf/conversions
INCLUDES = $(addprefix -I, $(INCLUDE_DIRS))

LIBFT		= $(LIBFT_DIR)/libft.a

# ----------------------------------------------------------------------------- #
# Sources
# ----------------------------------------------------------------------------- #

SRC			= client.c server.c utils_msg.c utils_signals.c

OBJ			= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# **************************************************************************** #
#                                 MAIN RULES                                   #
# **************************************************************************** #

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(LIBFT) $(OBJ_DIR)/server.o $(OBJ_DIR)/utils_msg.o $(OBJ_DIR)/utils_signals.o
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBFT)

$(NAME_CLIENT): $(LIBFT) $(OBJ_DIR)/client.o $(OBJ_DIR)/utils_msg.o $(OBJ_DIR)/utils_signals.o
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBFT)

# **************************************************************************** #
#                          COMPILATION DES .O                                  #
# **************************************************************************** #

$(OBJ_DIR)/%.o: %.c
	@$(MKDIR) $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# **************************************************************************** #
#                              LIBFT                                           #
# **************************************************************************** #

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# **************************************************************************** #
#                            CLEANING                                          #
# **************************************************************************** #

clean:
	$(RM) -r $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

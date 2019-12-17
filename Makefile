# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: croxane <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/01 16:26:48 by croxane           #+#    #+#              #
#    Updated: 2019/09/01 16:26:50 by croxane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fdf
PATH_SRC = ./
PATH_OBJ = ./
PATH_INC = ./libft

CC = gcc
CFLAGS =
HEAD = fdf.h

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RED_B = \033[1;4;31m
BLUE = \033[1;4;34m
RESET = \033[0m

SRC =	main.c \
		get_next_line.c \
		colour.c \
		filling.c \
		volume.c \
		push.c \
		ft_filling_part_two.c \
		print.c \
		iso.c \
		key.c

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))


all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	@echo "$(BLUE)Libft:$(GREEN) Creating Libft ...$(RESET)"
	@make -C libft/
	@echo "$(BLUE)Libft:$(GREEN) Libft.a is done$(RESET)"
	@$(CC) $(CFLAGS) -I $(PATH_INC) -c $(SRC)
	@echo "$(BLUE)$(NAME):$(GREEN) $(CC) $(CFLAGS) -I $(PATH_INC) -c $(SRC)$(RESET)"
	@$(CC) -o $(NAME) $(OBJ) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit
	@echo "$(BLUE)$(NAME):$(GREEN) $(CC) -o $(NAME) $(OBJ) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit$(RESET)"
	@echo "$(BLUE)$(NAME):$(GREEN) object files were created$(RESET)"
	@echo "$(BLUE)$(NAME):$(GREEN) $(NAME) was created$(RESET)"

.PHONY: clean fclean

clean:
	@echo "$(BLUE)Libft:$(RED) object files were deleted$(RESET)"
	@/bin/rm -f $(OBJ)
	@echo "$(BLUE)$(NAME):$(RED) object files were deleted$(RESET)"

fclean: clean
	@echo "$(BLUE)Libft:$(RED) Library libft.a was deleted$(RESET)"
	@/bin/rm -f $(NAME)
	@echo "$(BLUE)$(NAME):$(RED) fdf was deleted$(RESET)"

re: fclean all


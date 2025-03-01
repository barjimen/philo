# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 20:05:06 by barjimen          #+#    #+#              #
#    Updated: 2025/03/01 20:25:59 by barjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------ Executables

	NAME := philoshopers
	
#------ Folders

	SRC_DIR		:=		src/
	OBJ_DIR		:=		obj/
	LIB_DIR		:=		lib/
	INC_DIR		:=		inc/
	LFT_DIR		:=		$(LIB_DIR)Libft/

#--- Compile

	cc			:=		gcc
	CFLAGS		:=		-g -Wall -Wextra -Werror -fsanitize=address
	HEADER		:=		-I$(INC_DIR) -I$(LFT_DIR)

#--- .a LIBFT

	LIBFT		:=		$(LFT_DIR)libft.a

#--- .C
	
	SRC_FILES	:=		main  			 		\
						mutex					\
						routine					\
						utils					\
						lib						\
						monitor					\
						

#--- File variables

	SRC			=		$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
	OBJ			=		$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
	DEPS		=		$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))
	INCS		=		$(addprefix $(INCLUDE), $(addsuffix .h, $(INC_FILES)))

#--- Commands

RM				=		rm -f

#--- Cache

OBJF			=		.cache_exists_c

#---------------------------------- Second Part ----------------------------------

default:
			@$(MAKE) $(NAME)
all:	
		@$(MAKE) $(NAME)

makelibs:
			@$(MAKE) -C $(LFT_DIR)

-include	${DEPS}
$(NAME):	$(OBJ) makelibs
			@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) 

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(INCS) | $(OBJF)
			@$(CC) $(CFLAGS) -MMD -c $< -o $@
$(OBJF):
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)/automata
clean:
			@make clean -sC $(LFT_DIR)
			@$(RM) -rf $(OBJ_DIR)
fclean:		clean
			@$(RM) -f $(NAME)
			@make fclean -sC $(LFT_DIR)
re:			fclean
			@$(MAKE)

norminette:
			@norminette $(SRC) $(INCLUDE) | grep -v Norme -B1 || true
			@norminette $(INC_DIR) | grep -v Norme -B1 || true

PHONY: default all makelibs bonus clean fclean re norminette
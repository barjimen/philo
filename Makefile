# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 20:05:06 by barjimen          #+#    #+#              #
#    Updated: 2025/03/15 21:08:12 by barjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------ Executables

	NAME := philoshopers
	
#------ Folders

	SRC_DIR		:=		src/
	OBJ_DIR		:=		obj/
	INC_DIR		:=		inc/

#--- Compile

	cc			:=		gcc
	CFLAGS		:=		-g -Wall -Wextra -Werror 
	HEADER		:=		-I$(INC_DIR)

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


-include	${DEPS}
$(NAME):	$(OBJ)
			@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(INCS) | $(OBJF)
			@$(CC) $(CFLAGS) -MMD -c $< -o $@
$(OBJF):
			@mkdir -p $(OBJ_DIR)
clean:
			@$(RM) -rf $(OBJ_DIR)
fclean:		clean
			@$(RM) -f $(NAME)
re:			fclean
			@$(MAKE)

norminette:
			@norminette $(SRC) $(INCLUDE) | grep -v Norme -B1 || true
			@norminette $(INC_DIR) | grep -v Norme -B1 || true

PHONY: default all bonus clean fclean re norminette
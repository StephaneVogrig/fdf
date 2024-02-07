# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 19:41:13 by stephane          #+#    #+#              #
#    Updated: 2024/02/07 13:34:59 by svogrig          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	fdf

# sources ---------------------------------------------------------------------#

DIR_SRC		:=	src
SRC			:=	main.c \
				exit.c
SRC			:=	$(SRC:%=$(DIR_SRC)/%)

# includes --------------------------------------------------------------------#

DIR_INC		:=	/usr/include \
				mlx_linux \
				libft/include
I_FLAG	:=	$(addprefix -I,$(DIR_INC))
				
# objects ---------------------------------------------------------------------#

DIR_BUILD	:=	.build
OBJ			:=	$(SRC:$(DIR_SRC)/%.c=$(DIR_BUILD)/%.o)

# compilation -----------------------------------------------------------------#

CC			:=	cc
CC_FLAGS	:=	-Wall -Wextra -Werror

# make ------------------------------------------------------------------------#

MAKEFLAGS	+=	--no-print-directory

#------------------------------------------------------------------------------#
# rules                                                                        #
#------------------------------------------------------------------------------#

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -j -C libft
	@$(MAKE) -C mlx_linux
	@$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -Llibft -lft -fsanitize=address -o $(NAME)
	$(info created : $(NAME))
	
$(DIR_BUILD)/%.o: $(DIR_SRC)/%.c
	@mkdir -p $(@D)
	@$(CC) $(I_FLAG) -O3 -fsanitize=address -c $< -o $@
	$(info created : $@)

mlx_linux/libmlx_linux.a:
	$(info make lbmlx)
	@$(MAKE) -j -C mlx_linux

clean:
	@$(MAKE) -C libft clean
	@$(MAKE) -C mlx_linux clean
	@rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C libft fclean
	@rm -f $(NAME)

re: fclean
	@$(MAKE) all

run: $(NAME)
	@- ./fdf ../test_maps/42.fdf
#------------------------------------------------------------------------------#
# specifications                                                               #
#------------------------------------------------------------------------------#

.PHONY: all clean fclean re run
#.SILENT:
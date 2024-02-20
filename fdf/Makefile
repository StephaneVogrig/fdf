# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 19:41:13 by stephane          #+#    #+#              #
#    Updated: 2024/02/20 00:22:48 by svogrig          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	fdf

# sources ---------------------------------------------------------------------#

DIR_SRC		:=	src
SRC			:=	main.c \
				bresenham.c \
				draw_line.c \
				event.c \
				exit.c \
				fdf.c \
				image.c \
				map_load.c \
				map_move.c \
				map_to_img.c \
				mlx.c \
				pixel.c \
				projection.c \
				render.c \
				transform.c \
				window.c \
				zoom.c \
				color.c \
				draw_line_efla.c \
				debug.c

SRC			:=	$(SRC:%=$(DIR_SRC)/%)

# includes --------------------------------------------------------------------#

DIR_INC		:=	/usr/include \
				mlx_linux \
				libft/include
I_FLAG	:=	$(addprefix -I,$(DIR_INC))
				
# objects ---------------------------------------------------------------------#

DIR_BUILD	:=	.build
OBJ			:=	$(SRC:$(DIR_SRC)/%.c=$(DIR_BUILD)/%.o)
OBJ_SAN		:=	$(SRC:$(DIR_SRC)/%.c=$(DIR_BUILD)/sanitized/%.o)

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
	@$(CC) $(CC_FLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -Llibft -lft -o $(NAME)
	$(info created : $(NAME))
	
$(DIR_BUILD)/%.o: $(DIR_SRC)/%.c
	@mkdir -p $(@D)
	@$(CC) $(I_FLAG) -O3 -pg -c $< -o $@
	$(info created : $@)

$(DIR_BUILD)/sanitized/%.o: $(DIR_SRC)/%.c
	@mkdir -p $(@D)
	@$(CC) $(I_FLAG) -fsanitize=address -O3 -c $< -o $@
	$(info created : $@)

clean:
	@$(MAKE) -C libft clean
	@$(MAKE) -C mlx_linux clean
	@rm -f $(OBJ) $(OBJ_SAN)

fclean: clean
	@$(MAKE) -C libft fclean
	@rm -f $(NAME) $(NAME)_sanitized gmon.out

re: fclean
	@$(MAKE) all

run: $(NAME)
	@- ./fdf ../test_maps/elem-col.fdf

valgrind: $(NAME)
	@$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -Llibft -lft -g -o $(NAME)
	$(info valgrind created : $(NAME))
	@- valgrind --leak-check=full --track-origins=yes ./fdf ../test_maps/elem-col.fdf

sanitizer: $(OBJ_SAN)
	@$(CC) $(OBJ_SAN) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -Llibft -lft -fsanitize=address -o $(NAME)_sanitized
	@- ./fdf_sanitized ../test_maps/42.fdf

gprof:
	@$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -Llibft -lft -pg -o $(NAME)
	@- ./fdf ../test_maps/elem-col.fdf

#------------------------------------------------------------------------------#
# specifications                                                               #
#------------------------------------------------------------------------------#

.PHONY: all clean fclean re run mlx
#.SILENT:
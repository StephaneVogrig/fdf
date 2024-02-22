# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 19:41:13 by stephane          #+#    #+#              #
#    Updated: 2024/02/21 21:24:13 by svogrig          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	fdf
NAME_BONUS	:=	fdf_bonus

# sources ---------------------------------------------------------------------#

DIR_SRC		:=	src
SRC			:=	main.c \
				bresenham.c \
				draw_line.c \
				event.c \
				fdf.c \
				image.c \
				map_load.c \
				map_to_img.c \
				transform.c \
				color.c

SRC			:=	$(SRC:%=$(DIR_SRC)/%)

# sources bonus ---------------------------------------------------------------#

DIR_BONUS	:=	bonus
SRC_BONUS	:=	main_bonus.c \
				bresenham_bonus.c \
				color_bonus.c \
				draw_line_bonus.c \
				event_bonus.c \
				event_mouse_bonus.c \
				fdf_bonus.c \
				image_bonus.c \
				map_load_bonus.c \
				map_move_bonus.c \
				map_to_img_bonus.c \
				projection_bonus.c \
				render_bonus.c \
				transform_bonus.c \
				zoom_bonus.c

SRC_BONUS	:=	$(SRC_BONUS:%=$(DIR_SRC)/$(DIR_BONUS)/%)

# includes --------------------------------------------------------------------#

DIR_INC		:=	/usr/include \
				mlx_linux \
				libft/include
I_FLAG	:=	$(addprefix -I,$(DIR_INC))
				
# objects ---------------------------------------------------------------------#

DIR_BUILD	:=	.build
OBJ			:=	$(SRC:$(DIR_SRC)/%.c=$(DIR_BUILD)/%.o)
OBJ_SAN		:=	$(SRC:$(DIR_SRC)/%.c=$(DIR_BUILD)/sanitized/%.o)
OBJ_BONUS	:=	$(SRC_BONUS:$(DIR_SRC)/%.c=$(DIR_BUILD)/%.o)

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

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) 
	@$(MAKE) -j -C libft
	@$(MAKE) -C mlx_linux
	@$(CC) $(CC_FLAGS) $(OBJ_BONUS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -Llibft -lft -o $(NAME_BONUS)
	$(info created : $(NAME_BONUS))

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
	@rm -f $(OBJ) $(OBJ_BONUS) $(OBJ_SAN)

fclean: clean
	@$(MAKE) -C libft fclean
	@rm -f $(NAME) $(NAME_BONUS) $(NAME)_sanitized gmon.out 

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
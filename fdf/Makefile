# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 19:41:13 by stephane          #+#    #+#              #
#    Updated: 2024/02/22 22:22:43 by svogrig          ###   ########.fr        #
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
				color_gradient.c

SRC			:=	$(SRC:%=$(DIR_SRC)/%)

# sources bonus ---------------------------------------------------------------#

SRC_BONUS	:=	bresenham.c \
				color_gradient.c \
				draw_line.c \
				image.c \
				bonus/map_load_bonus.c \
				bonus/main_bonus.c \
				bonus/color_game_bonus.c \
				bonus/color_gradient_bonus.c \
				bonus/event_bonus.c \
				bonus/event_mouse_bonus.c \
				bonus/fdf_bonus.c \
				bonus/map_earth_bonus.c \
				bonus/map_transform_bonus.c \
				bonus/map_to_img_bonus.c \
				bonus/projection_bonus.c \
				bonus/render_bonus.c \
				bonus/transform_bonus.c \
				bonus/z_bonus.c \
				bonus/zoom_bonus.c

SRC_BONUS	:=	$(SRC_BONUS:%=$(DIR_SRC)/%)


# includes --------------------------------------------------------------------#

DIR_INC		:=	/usr/include \
				mlx_linux \
				libft/include \
				include
I_FLAG		:=	$(addprefix -I,$(DIR_INC))
				
# library ---------------------------------------------------------------------#

L_FLAG		:=	mlx_linux \
				/usr/lib \
				libft

L_FLAG		:=	$(addprefix -L,$(L_FLAG))

l_FLAG		:=	mlx_Linux \
				Xext \
				X11 \
				m \
				z \
				ft

l_FLAG		:=	$(addprefix -l,$(l_FLAG))

# objects ---------------------------------------------------------------------#

DIR_BUILD	:=	.build
OBJ			:=	$(SRC:$(DIR_SRC)/%.c=$(DIR_BUILD)/%.o)
OBJ_SAN		:=	$(SRC:$(DIR_SRC)/%.c=$(DIR_BUILD)/sanitized/%.o)
OBJ_BONUS	:=	$(SRC_BONUS:$(DIR_SRC)/%.c=$(DIR_BUILD)/%.o)

DEPS		:=	$(OBJ:.o=.d) $(OBJ_SAN:.o=.d) $(OBJ_BONUS:.o=.d)

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
	@$(CC) $(CC_FLAGS) $(OBJ) $(L_FLAG) $(l_FLAG) -o $(NAME)
	$(info created : $(NAME))

bonusonly: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) 
	@$(MAKE) -j -C libft
	@$(MAKE) -C mlx_linux
	@$(CC) $(CC_FLAGS) $(OBJ_BONUS) $(L_FLAG) $(l_FLAG) -o $(NAME_BONUS)
	$(info created : $(NAME_BONUS))

$(DIR_BUILD)/%.o: $(DIR_SRC)/%.c
	@mkdir -p $(@D)
	@$(CC) $(I_FLAG) -O3 -pg -c $< -o $@
	$(info created : $@)

$(DIR_BUILD)/sanitized/%.o: $(DIR_SRC)/%.c
	@mkdir -p $(@D)
	@$(CC) $(I_FLAG) -fsanitize=address -O3 -c $< -o $@
	$(info created : $@)

-include $(DEPS)

clean:
	@$(MAKE) -C libft clean
	@$(MAKE) -C mlx_linux clean
	@rm -f $(OBJ) $(OBJ_BONUS) $(OBJ_SAN) $(DEPS)

fclean: clean
	@$(MAKE) -C libft fclean
	@rm -f $(NAME) $(NAME_BONUS) $(NAME)_sanitized gmon.out 

re: fclean
	@$(MAKE) -j all

rebonus: fclean
	@$(MAKE) -j bonusonly

bonus:
	@$(MAKE) -j bonusonly

run: $(NAME)
	@- ./fdf ../test_maps/elem-col.fdf

valgrind: $(NAME)
	@$(CC) $(OBJ) $(L_FLAG) $(L_FLAG) $(l_FLAG)  -g -o $(NAME)
	$(info valgrind created : $(NAME))
	@- valgrind --leak-check=full --track-origins=yes --track-fds=yes ./fdf test_maps/elem-col.fdf

sanitizer: $(OBJ_SAN)
	@$(CC) $(OBJ_SAN) $(L_FLAG) $(L_FLAG) $(l_FLAG) -fsanitize=address -o $(NAME)_sanitized
	@- ./fdf_sanitized test_maps/42.fdf

gprof:
	@$(CC) $(OBJ) $(L_FLAG) $(L_FLAG) $(l_FLAG) -pg -o $(NAME)
	@- ./fdf test_maps/elem-col.fdf

#------------------------------------------------------------------------------#
# specifications                                                               #
#------------------------------------------------------------------------------#

.PHONY: all clean fclean re run mlx
#.SILENT:
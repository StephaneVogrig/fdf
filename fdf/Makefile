# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 19:41:13 by stephane          #+#    #+#              #
#    Updated: 2024/02/25 13:57:26 by svogrig          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	fdf
NAME_BONUS	:=	fdf_bonus
NAME_DEBUG	:=	fdf_debug
NAME_DEBUGB	:=	fdf_bonusdebug
NAME_SAN	:=	fdf_sanitize
NAME_SANB	:=	fdf_bonussanitize

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
I_FLAG		:=	$(addprefix -I,$(DIR_INC)) -MMD -MP
				
# library ---------------------------------------------------------------------#

LIB_FT		:=	libft/libf.a
LIB_MLX		:=	mlx_linux/libmlx_linux.a

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
OBJ_BONUS	:=	$(SRC_BONUS:$(DIR_SRC)/%.c=$(DIR_BUILD)/%.o)
OBJ_DEBUG	:=	$(SRC:$(DIR_SRC)/%.c=$(DIR_BUILD)/debug/%.o)
OBJ_DEBUGB	:=	$(SRC_BONUS:$(DIR_SRC)/%.c=$(DIR_BUILD)/debugbonus/%.o)
OBJ_SAN		:=	$(SRC:$(DIR_SRC)/%.c=$(DIR_BUILD)/sanitize/%.o)
OBJ_SANB	:=	$(SRC_BONUS:$(DIR_SRC)/%.c=$(DIR_BUILD)/sanitize/%.o)

DEPS		:=	$(OBJ:.o=.d) $(OBJ_SAN:.o=.d) $(OBJ_BONUS:.o=.d)

# compilation -----------------------------------------------------------------#

CC			:=	cc
CC_FLAGS	:=	-Wall -Wextra -Werror

DEBUG_FLAGS	:=	-g
VAL_FLAGS	:=	--leak-check=full --track-origins=yes --track-fds=yes
SAN_FLAGS	:=	-fsanitize=address -g

# make ------------------------------------------------------------------------#

MAKEFLAGS	+=	--no-print-directory

#------------------------------------------------------------------------------#
# rules                                                                        #
#------------------------------------------------------------------------------#

all:
	@$(MAKE) -j makeall

clean:
	@$(MAKE) -C libft clean
	@rm -rf $(DIR_BUILD)
#	@rm -f $(OBJ) $(OBJ_BONUS) $(OBJ_DEBUG) $(OBJ_SAN) $(OBJ_DEBUGB) $(OBJ_SANB) $(DEPS)

fclean:
	@$(MAKE) -C libft fclean
	@$(MAKE) -C mlx_linux clean
	@rm -rf $(DIR_BUILD)
	@rm -f	$(NAME) \
			$(NAME_BONUS) \
			$(NAME_DEBUG) \
			$(NAME_SAN) \
			$(NAME_DEBUGB) \
			$(NAME_SANB)

re: fclean
	@$(MAKE) -j makeall

bonus:
	@$(MAKE) -j makebonus

rebonus: fclean bonus

run: all
	@- ./$(NAME) test_maps_2/France.XXL.fdf

runbonus: bonus
	@- ./$(NAME_BONUS) test_maps_2/France.XXL.fdf

debug:
	@$(MAKE) -j makedebug

debugbonus:
	@$(MAKE) -j makedebugb

valgrind: debug
	@- valgrind $(VAL_FLAGS) ./$(NAME_DEBUG) test_maps/elem-col.fdf

valgrindbonus: debugbonus
	@- valgrind $(VAL_FLAGS) ./$(NAME_DEBUGB) test_maps/elem-col.fdf

sanitize:
	@$(MAKE) -j makesanitize
	@- ./$(NAME_SAN) test_maps/elem-col.fdf

sanitizebonus:
	@$(MAKE) -j makesanitizeb
	@- ./$(NAME_SANB) test_maps/elem-col.fdf

makeall:		$(NAME)
makebonus:		$(NAME_BONUS)
makedebug:		$(NAME_DEBUG)
makedebugb:		$(NAME_DEBUGB)
makesanitize:	$(NAME_SAN)
makesanitizeb:	$(NAME_SANB)

$(NAME): $(OBJ) $(LIB_MLX) $(LIB_FT)
	@$(CC) $(CC_FLAGS) $(OBJ) $(L_FLAG) $(l_FLAG) -o $(NAME)
	$(info created : $(NAME))

$(NAME_BONUS): $(OBJ_BONUS) $(LIB_MLX) $(LIB_FT)
	@$(CC) $(CC_FLAGS) $(OBJ_BONUS) $(L_FLAG) $(l_FLAG) -o $(NAME_BONUS)
	$(info created : $(NAME_BONUS))

$(NAME_DEBUG): $(OBJ_DEBUG) $(LIB_MLX) $(LIB_FT)
	@$(CC) $(CC_FLAGS) $(OBJ_DEBUG) $(L_FLAG) $(l_FLAG) -g -o $(NAME_DEBUG)
	$(info created : $(NAME_DEBUG))

$(NAME_DEBUGB): $(OBJ_DEBUGB) $(LIB_MLX) $(LIB_FT)
	@$(CC) $(CC_FLAGS) $(OBJ_DEBUGB) $(L_FLAG) $(l_FLAG) -g -o $(NAME_DEBUGB)
	$(info created : $(NAME_DEBUGB))

$(NAME_SAN): $(OBJ_SAN) $(LIB_MLX) $(LIB_FT)
	@$(CC) $(OBJ_SAN) $(L_FLAG) $(l_FLAG) $(SAN_FLAGS) -o $(NAME_SAN)
	$(info created : $(NAME_SAN))

$(NAME_SANB): $(OBJ_SANB) $(LIB_MLX) $(LIB_FT)
	@$(CC) $(OBJ_SANB) $(L_FLAG) $(l_FLAG) $(SAN_FLAGS) -o $(NAME_SANB)
	$(info created : $(NAME_SANB))

$(DIR_BUILD)/%.o: $(DIR_SRC)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CC_FLAGS) $(I_FLAG) -pg -c $< -o $@
	$(info created : $@)

$(DIR_BUILD)/debug/%.o: $(DIR_SRC)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CC_FLAGS) $(I_FLAG) $(DEBUG_FLAGS) -c $< -o $@
	$(info created : $@)

$(DIR_BUILD)/debugbonus/%.o: $(DIR_SRC)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CC_FLAGS) $(I_FLAG) $(DEBUG_FLAGS) -c $< -o $@
	$(info created : $@)

$(DIR_BUILD)/sanitize/%.o: $(DIR_SRC)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CC_FLAGS) $(I_FLAG) $(SAN_FLAGS) -c $< -o $@
	$(info created : $@)

$(LIB_FT):
	@$(MAKE) -j -C libft

$(LIB_MLX):
	@$(MAKE) -j -C mlx_linux

-include $(DEPS)

#------------------------------------------------------------------------------#
# specifications                                                               #
#------------------------------------------------------------------------------#

.PHONY: all \
		clean \
		fclean \
		re \
		bonus \
		rebonus \
		run \
		runbonus \
		debug \
		debugbonus \
		valgrind \
		valgrindbonus \
		sanitize \
		sanitizebonus \
		makeall \
		makebonus \
		makedebug \
		makedebugb \
		makesanitize \
		makesanitizeb

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 02:59:52 by svogrig           #+#    #+#              #
#    Updated: 2024/02/22 03:33:29 by svogrig          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
# variables                                                                    #
#------------------------------------------------------------------------------#

NAME = libft.a

INCS		:=	include

SRC_DIR		:=	src
SRCS 		:=	char/ft_isalnum.c \
				char/ft_isalpha.c \
				char/ft_isascii.c \
				char/ft_isdigit.c \
				char/ft_isprint.c \
				char/ft_toupper.c \
				char/ft_tolower.c \
				char/is_hexagit.c \
				color/color.c \
				error/error_msg.c \
				error/error_perror.c \
				int/ft_atoi.c \
				int/ft_abs.c \
				int/atoi_offset.c \
				int/ft_itoa.c \
				int/hexatoi_offset.c \
				int/si32_min.c \
				int/si32_max.c \
				int/si32_to_decstr_offset.c \
				lst/ft_lstadd_back.c \
				lst/ft_lstadd_front.c \
				lst/ft_lstclear.c \
				lst/ft_lstdelone.c \
				lst/ft_lstiter.c \
				lst/ft_lstlast.c \
				lst/ft_lstmap.c \
				lst/ft_lstnew.c \
				lst/ft_lstsize.c \
				mem/ft_bzero.c \
				mem/ft_calloc.c \
				mem/ft_memchr.c \
				mem/ft_memcmp.c \
				mem/ft_memcpy.c \
				mem/ft_memmove.c \
				mem/ft_memset.c \
				pixel/pixel.c \
				put/ft_putchar_fd.c \
				put/ft_putendl_fd.c \
				put/ft_putnbr_fd.c \
				put/ft_putstr_fd.c \
				str/ft_split.c \
				str/ft_strchr.c \
				str/ft_strcmp.c \
				str/ft_strdup.c \
				str/ft_striteri.c \
				str/ft_strjoin.c \
				str/ft_strlcat.c \
				str/ft_strlcpy.c \
				str/ft_strlen.c	\
				str/ft_strmapi.c \
				str/ft_strncmp.c \
				str/ft_strnstr.c \
				str/ft_strrchr.c \
				str/ft_strtrim.c \
				str/ft_substr.c \
				str/strcpy_offset.c \
				tabsi32/tabsi32_init.c \
				tabsi32/tabsi32_print.c \
				ft_printf/ft_printf.c \
				ft_printf/buffer.c \
				ft_printf/format_c.c \
				ft_printf/format_f.c \
				ft_printf/format_i.c \
				ft_printf/format_p.c \
				ft_printf/format_purcent.c \
				ft_printf/format_s.c \
				ft_printf/format_u.c \
				ft_printf/format_x.c \
				ft_printf/format_xupper.c \
				ft_printf/field.c \
				ft_printf/float64_get.c \
				ft_printf/nbr_digit.c \
				ft_printf/nbrstr_to_buffer.c \
				ft_printf/parsing.c \
				ft_printf/set_specification.c \
				ft_printf/spec_str_to_int.c \
				ft_printf/ui64_to_str.c \
				ft_printf/vs_10pow.c \
				unit_test/unit_test.c \
				vector/vector2f.c \
				vector/vector3f.c \
				vector/vector2i.c \
				vector/vector3i.c \
				get_next_line.c

SRCS		:=	$(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR	:= 	.build
OBJS 		:=	$(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

DEPS		:=	$(OBJS:.o=.d)

CC			:=	cc
CFLAGS		:= 	-Wall -Wextra -Werror 
CPPFLAGS	:=	$(addprefix -I,$(INCS)) -MMD -MP

AR			:=	ar
ARFLAGS		:=	-r -c -s

RM			:=	rm -f
MAKEFLAGS	+=	--no-print-directory
DIR_DUP		=	mkdir -p $(@D)

#------------------------------------------------------------------------------#
# rules                                                                        #
#------------------------------------------------------------------------------#

all : $(NAME)
	
$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	$(info created: $@)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info created: $@)

-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS)
	
fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

#------------------------------------------------------------------------------#
# specifications                                                               #
#------------------------------------------------------------------------------#

.PHONY: all clean fclean re
.SILENT:

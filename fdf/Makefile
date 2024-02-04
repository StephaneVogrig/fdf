#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stephane <stephane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 19:41:13 by stephane          #+#    #+#              #
#    Updated: 2024/02/04 22:10:54 by stephane         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	:=	fdf

SRC		:=	main.c

OBJ		:=	$(SRC:%.c=%.o)

# compilation -----------------------------------------------------------------#
CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror

#------------------------------------------------------------------------------#
# rules                                                                        #
#------------------------------------------------------------------------------#

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	
%.o: %.c
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@
#	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	
re:
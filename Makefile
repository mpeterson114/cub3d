
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/18 18:25:20 by ilzhabur          #+#    #+#              #
#    Updated: 2024/07/12 14:12:48 by mpeterso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ORANGE =		\033[38;5;209m
PURPLE=			\033[0;35m
YELLOW =		\033[0;93m
GREEN =			\033[0;92m
WHITE =			\033[0;37m

NAME = cub3d

SRC = src/main.c \
		src/parser.c \
		src/utils.c \
		src/read_file.c \
		src/map_values.c \
		src/check_walls.c \
		#src/game.c \
		src/player.c \
		src/rendering.c \
		src/raycasting.c \
		src/screen_utils.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

LIBDIR = libft/
LIBNAME = libft.a
LIBFT = $(LIBDIR)$(LIBNAME)

UNAME = $(shell uname)
ifeq ($(UNAME),Linux)
	MINDIR	= 	mlx_linux
	MINLIBX	=	libmlx.a
	MLX_FLAGS = -I$(MINDIR) -lXext -lX11 -lm -lz
else
	MINDIR	= 	mlx_mac
	MINLIBX	=	libmlx.a
	MLX_FLAGS = -framework OpenGL -framework AppKit 
endif

HEADERS	=	src/cub3d.h gnl/get_next_line.h libft/libft.h

SRC		=	$(wildcard gnl/*.c)	\
			$(wildcard src/*.c)

OBJ		=	$(patsubst %.c,%.o,$(SRC))

all		:	$(NAME)


$(NAME)	: $(OBJ) $(HEADERS)
		@make -sC $(LIBDIR)/ 
		@cp	$(LIBDIR)/$(LIBFT) . 
		@make -sC $(MINDIR)/ 
		@cp	$(MINDIR)/$(MINLIBX) . 
		@$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(MINLIBX) -o $(NAME) -L$(MINDIR) -lmlx $(MLX_FLAGS)  
		
clean:
		@rm -rf $(OBJ)
		@make -C $(LIBDIR) clean 
		@make -C $(MINDIR) clean 

fclean: clean
		@make -C $(LIBDIR) fclean 
		@rm -f $(NAME)
		@rm -f $(MINLIBX)
		@rm -f $(LIBFT)
		
re: 	fclean all
	

.PHONY	:	all clean fclean re




# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jna <jna@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/24 02:40:34 by jna               #+#    #+#              #
#    Updated: 2021/05/24 22:40:58 by jna              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	cub3D

##########################
# compile & flag options #
##########################
CC		=	gcc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit


##########################
# sources				 #
##########################
SRCS	=	./codes/begin_game.c 			\
			./codes/cal_sprite.c			\
			./codes/cub3d.c 				\
			./codes/draw_utils.c			\
			./codes/error_msg.c 			\
			./codes/game.c 					\
			./codes/init_info.c 			\
			./codes/init_player.c 			\
			./codes/init_sprite.c 			\
			./codes/key_press.c 			\
			./codes/load_textures.c 		\
			./codes/parsing_elements.c 		\
			./codes/parsing_map.c 			\
			./codes/parsing_path.c 			\
			./codes/parsing.c 				\
			./codes/ray_casting_dda.c 		\
			./codes/ray_casting_draw.c 		\
			./codes/ray_casting_sprite.c 	\
			./codes/save_bmp.c 				\
			./codes/start_game.c 			\
			./codes/valid_arg.c 			\
			./codes/valid_wall.c 			\
			./codes/valid_utils.c			\
			./codes/key_released.c			\

##########################
# librarys sources		 #
##########################
LIBS	=	./librarys/get_next_line/get_next_line.c 		\
			./librarys/get_next_line/get_next_line_utils.c 	\
			./librarys/libft/ft_atoi.c				 		\
			./librarys/libft/ft_bzero.c				 		\
			./librarys/libft/ft_isdigit.c					\
			./librarys/libft/ft_split.c						\
			./librarys/libft/ft_strchr.c					\
			./librarys/libft/ft_strncmp.c					\
			./librarys/libft/ft_strs_len.c 					\


##########################
# basic macro			 #
##########################

all:		$(NAME)

$(NAME):
			$(CC) -o $(NAME) $(SRCS) $(LIBS)

clean:
			rm -f *.o

fclean:		clean
			rm -f $(NAME)

re:			fclean all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epimenta <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/06 17:47:58 by epimenta          #+#    #+#              #
#    Updated: 2016/12/07 01:14:48 by ltsiaras         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = ./srcs/

HEADER = ./include/

FC = $(SRC)main.c $(SRC)ft_open_file.c $(SRC)ft_check_tetris.c \
$(SRC)ft_libft.c $(SRC)ft_motif.c $(SRC)ft_motif_sf.c $(SRC)ft_list.c \
$(SRC)ft_cut_motif.c $(SRC)ft_resolve.c $(SRC)ft_print.c \
$(SRC)ft_resolve_final.c

FO = main.o ft_open_file.o ft_check_tetris.o ft_libft.o ft_motif.o \
ft_motif_sf.o ft_list.o ft_cut_motif.o ft_resolve.o ft_print.o \
ft_resolve_final.o

FLAGS = -Wall -Werror -Wextra

.PHONY: all clean fclean re

.NOTPARALLEL: re

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(FC) -I $(HEADER)
	gcc $(FLAGS) $(FO) -o $(NAME)

clean:
	/bin/rm -f $(FO)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

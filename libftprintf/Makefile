# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nwattana <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 13:10:10 by nwattana          #+#    #+#              #
#    Updated: 2022/06/14 07:56:40 by nwattana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =libftprintf.a

SRC_DIR = ./srcs

SRC = ft_printf.c \
      format_collect.c \
      ft_isin.c \
      ft_itoa_uint.c \
      number_base_len.c \
      number_base_len_p.c \
      put_c.c \
      put_di.c \
      put_format.c \
      put_p.c \
      put_s.c \
      put_u.c \
      put_x.c \
      put_x_p.c\
      put_percent.c \
      put_charloop.c\
      ft_itoa_hexa.c \
      ft_itoa_hexa_p.c

SRC_DIR = ./srcs
INC_DIR = ./includes

OBJ = ${SRC:%.c=%.o}

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a

CC = gcc
CFLAG = -Wall -Wextra -Werror

all : ${NAME}
	@printf "\e[1;32m%s\e[0m\n" "LIBFT_PRINTF---Done"

${NAME} : ${OBJ} ${LIBFT}
	@ar rc ${NAME} ${OBJ}

${OBJ}:%.o:${SRC_DIR}/%.c
	@${CC} ${CFLAG} -I ${INC_DIR} -I ${LIBFT_DIR} -c $< -o $@

${LIBFT}:
	make -C ${LIBFT_DIR} re
	@cp ${LIBFT} ${NAME}

bonus : all

clean :
	@rm -f *.o */*.o
	make -C ${LIBFT_DIR} clean

fclean : clean
	@rm -f ${NAME}
	make -C ${LIBFT_DIR} fclean

re : fclean all

.PHONY: all clean fclean re bonus

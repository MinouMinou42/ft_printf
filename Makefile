# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nolivier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/23 12:26:44 by nolivier          #+#    #+#              #
#    Updated: 2017/03/01 12:23:31 by nolivier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_strlen.c \
	  ft_strjoin.c \
	  ft_strdup.c \
	  ft_atoi.c \
	  ft_isdigit.c \
	  ft_strsub.c \
	  ft_strchr.c \
	  ft_printf.c \
	  ft_dprintf.c \
	  ft_len_w.c \
	  ft_len_p.c \
	  ft_len_type.c \
	  ft_len_flag.c \
	  ft_read_flag.c \
	  ft_write_flag.c \
	  ft_convert_flag.c \
	  ft_convert_type.c \
	  ft_isconvers.c \
	  ft_isflag.c \
	  ft_read_width.c \
	  ft_read_preci.c \
	  ft_put_sign.c \
	  ft_put_n.c \
	  ft_choose_type.c \
	  ft_itoa_long.c \
	  ft_itoa_ulong.c \
	  ft_itoa_olong.c \
	  ft_itoa_xlong.c \
	  ft_itoa_upxlong.c \
	  ft_itoa_blong.c \
	  ft_unicode_two.c \
	  ft_unicode_three.c \
	  ft_unicode_four.c \
	  ft_put_wi.c \
	  ft_put_wc.c \
	  ft_joinfree.c \
	  ft_flag_percent.c \
	  ft_flag_c.c \
	  ft_flag_s.c \
	  ft_flag_d.c \
	  ft_flag_u.c \
	  ft_flag_p.c \
	  ft_flag_o.c \
	  ft_flag_x.c \
	  ft_flag_upc.c \
	  ft_flag_ups.c \
	  ft_flag_upd.c \
	  ft_flag_upu.c \
	  ft_flag_upo.c \
	  ft_flag_upx.c \
	  ft_flag_b.c \
	  ft_flag_color.c \
	  ft_flag_none.c

OUT = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	gcc $(FLAG) -c -o $@ $^

$(NAME): $(OUT)
	ar rc $(NAME) $(OUT)

clean:
	/bin/rm -f $(OUT)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

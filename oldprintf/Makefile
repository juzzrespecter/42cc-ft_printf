#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danrodri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/17 18:02:40 by danrodri          #+#    #+#              #
#    Updated: 2020/01/21 15:04:25 by danrodri         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY		= all re clean fclean bonus

SRCS		= write_hex.c write_dec.c write_char.c write_ptr.c write_percent_n.c write_str.c write_udec.c ft_printf.c flags_functions.c ft_ulltoa_base.c ft_printf_utils.c u8_encoder.c

OBJS		= $(SRCS:.c=.o)

NAME		= libftprintf.a

FLAGS		= -Werror -Wextra -Wall

RM		= rm -f

$(NAME):
		@gcc -c $(FLAGS) $(SRCS)
		@make -C libft
		@mv libft/libft.a ./$(NAME)
		@ar rcs $(NAME) $(OBJS)

all:		$(NAME)

clean:
		@$(RM) $(OBJS)
		@make clean -C libft

fclean:		clean
		@$(RM) $(NAME)

re:		fclean all

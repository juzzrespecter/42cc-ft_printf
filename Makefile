#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danrodri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/09 18:05:59 by danrodri          #+#    #+#              #
#    Updated: 2020/01/12 19:55:32 by danrodri         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY:		all clean fclean re bonus

NAME		= libftprintf.a

SRCS		= ft_printf.c ft_printf_conv.c ft_printf_conv_2.c ft_printf_parser.c ft_printf_conv_utils.c

OBJS		= $(SRCS:.c=.o)

CFLAGS		= -Wall -Werror -Wextra

RM		= rm -f

$(NAME):
		@make -C libft
		@mv libft/libft.a ./$(NAME)
		@cc $(CFLAGS) -c $(SRCS)
		@ar rcs $(NAME) $(OBJS)

all:		$(NAME)

clean:
		@$(RM) $(OBJS)

fclean:		clean
		@$(RM) $(NAME)

re:		fclean all

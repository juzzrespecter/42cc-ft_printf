.PHONY:		all re bonus clear fclear

NAME		= libftprintf.a

SRCS		= ft_printf.c ft_printf_parse.c writefuncs.c

OBJS		= $(SRCS:.c=.o)

RM		= rm -f

CFLAGS		= -Wall -Werror -Wextra

$(NAME):
		@make -C libft
		@cp libft/libft.a ./libftprintf.a
		@gcc $(CFLAGS) -c $(SRCS)
		@ar rcs $(NAME) $(OBJS)

all:		$(NAME)

clean:
		@make clean -C libft
		@$(RM) $(OBJS)

fclean:		clean
		@make fclean -C libft
		@$(RM) $(NAME)

re:		fclean all

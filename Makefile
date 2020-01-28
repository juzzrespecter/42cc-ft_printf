#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danrodri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/17 18:02:40 by danrodri          #+#    #+#              #
#    Updated: 2020/01/28 19:19:19 by danrodri         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY		= all re clean fclean bonus

SRCS		= ft_printf.c

SRCS_DIR	= srcs/

SRCS_TYPE	= x_type.c \
			d_type.c \
			c_type.c \
			p_type.c \
			s_type.c \
			per_type.c \
			u_type.c

SRCS_TYPE_DIR	= srcs/types/

SRCS_FMT	= flag_format.c \
			minfieldwidth_format.c \
			prec_format.c

SRCS_FMT_DIR	= srcs/format/

SRCS_UTILS	= ft_ultoa_base.c \
			ft_strcap.c

SRCS_UTILS_DIR	= srcs/utils/

INCL_DIR	= includes/

OBJS_TYPE	= $(patsubst %.c,$(OBJS_DIR)%.o,$(SRCS_TYPE))

OBJS_FMT	= $(patsubst %.c,$(OBJS_DIR)%.o,$(SRCS_FMT))

OBJS_UTILS	= $(patsubst %.c,$(OBJS_DIR)%.o,$(SRCS_UTILS))

OBJS		= $(patsubst %.c,$(OBJS_DIR)%.o,$(SRCS))

OBJS_DIR	= objs/

NAME		= libftprintf.a

FLAGS		= -Werror -Wextra -Wall

RM		= rm -f

RMDIR		= rm -rf

all:		$(NAME)

$(NAME):	$(OBJS_TYPE) $(OBJS_FMT) $(OBJS_UTILS) $(OBJS)
			@make -C libft
			@mv libft/libft.a ./$(NAME)
			@ar rcs $(NAME) $(OBJS_TYPE) $(OBJS_FMT) $(OBJS_UTILS) $(OBJS)

$(OBJS_DIR)%.o:	$(SRCS_TYPE_DIR)%.c
			@gcc $(FLAGS) -c -I$(INCL_DIR)libftprintf.h $<
			@mkdir -p $(OBJS_DIR)
			@mv -f $(@F) $(OBJS_DIR)

$(OBJS_DIR)%.o:	$(SRCS_FMT_DIR)%.c
			@gcc $(FLAGS) -c -I$(INCL_DIR)libftprintf.h $<
			@mkdir -p $(OBJS_DIR)
			@mv -f $(@F) $(OBJS_DIR)

$(OBJS_DIR)%.o:	$(SRCS_UTILS_DIR)%.c
			@gcc $(FLAGS) -c -I$(INCL_DIR)libftprintf.h $<
			@mkdir -p $(OBJS_DIR)
			@mv -f $(@F) $(OBJS_DIR)

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
			@gcc $(FLAGS) -c -I$(INCL_DIR)libftprintf.h $<
			@mkdir -p $(OBJS_DIR)
			@mv -f $(@F) $(OBJS_DIR)

clean:
			@$(RM) $(OBJ_DIR) $(OBJS)
			@$(RMDIR) $(OBJS_DIR)
			@make clean -C libft

fclean:		clean
			@$(RM) $(NAME)

bonus:		$(all)

re:			fclean all

normi:
			@norminette  $(INCL_DIR)libftprintf.h \
								$(SRCS_DIR)*.c \
								$(SRCS_FMT_DIR)*.c \
								$(SRCS_UTILS_DIR)*.c \
								$(SRCS_TYPE_DIR)*.c

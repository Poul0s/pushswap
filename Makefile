# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psalame <psalame@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 11:02:12 by psalame           #+#    #+#              #
#    Updated: 2023/11/19 15:34:48 by psalame          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	push_swap

SRCS	=	pile/create.c \
			pile/add_remove.c \
			pile/free.c \
			pile/initialise.c \
			pile/push.c \
			pile/rotate.c \
			pile/swap.c \
			sort/do_action.c \
			sort/is_sort.c \
			sort/sort.c \
			sort/short_sort.c \
			ft_isnumber.c \
			push_swap.c

OBJS	=	$(SRCS:.c=.o)

HEADER	=	.

LIBFT_PATH	= ./libft

LIBFT	= $(LIBFT_PATH)/libft.a

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(COMP_CFLAGS) $(OBJS) -lft -L$(LIBFT_PATH) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(COMP_CFLAGS) -c $^ -lft -L$(LIBFT_PATH) -I $(HEADER) -I $(LIBFT_PATH)/header -o $@

clean:
	make -C $(LIBFT_PATH) clean
	rm -rf $(OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: bonus all clean fclean re

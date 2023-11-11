# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psalame <psalame@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 11:02:12 by psalame           #+#    #+#              #
#    Updated: 2023/11/12 00:20:44 by psalame          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	push_swap

SRCS	=	pile_utils/create.c \
			pile_utils/add_remove.c \
			pile_utils/get_largest_number_pos.c \
			pile_utils/push.c \
			pile_utils/rotate.c \
			pile_utils/swap.c \
			push_swap.c 

OBJS	=	$(SRCS:.c=.o)

HEADER	=	.

LIBFT_PATH	= ./libft

LIBFT	= $(LIBFT_PATH)/libft.a

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L $(LIBFT_PATH) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -L $(LIBFT_PATH) -lft -I $(HEADER) -I $(LIBFT_PATH)/header -o $@

clean:
	make -C $(LIBFT_PATH) clean
	rm -rf $(OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: bonus all clean fclean re

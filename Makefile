# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psalame <psalame@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 11:02:12 by psalame           #+#    #+#              #
#    Updated: 2023/11/25 02:51:04 by psalame          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

NAME		=	push_swap

SRCS		=	pile/create.c \
				pile/add_remove.c \
				pile/free.c \
				pile/initialise.c \
				pile/push.c \
				pile/rotate.c \
				pile/swap.c \
				sort/do_action.c \
				sort/is_sort.c \
				sort/sort.c \
				sort/algorithm/short_sort.c \
				sort/algorithm/big_sort/big_sort.c \
				sort/algorithm/big_sort/cost_calcul.c \
				sort/algorithm/big_sort/extreme_value.c \
				ft_isnumber.c \
				arguments.c \
				push_swap.c \
				error.c

OBJS		=	$(addprefix obj/, $(SRCS:.c=.o))

OBJS_DIRS	=	$(sort $(dir $(OBJS)))

BSRCS		=	pile/create.c \
				pile/add_remove.c \
				pile/free.c \
				pile/initialise.c \
				pile/push.c \
				pile/rotate.c \
				pile/swap.c \
				sort/algorithm/big_sort/extreme_value.c \
				sort/is_sort.c \
				arguments.c \
				ft_isnumber.c \
				checker_bonus/checker_bonus.c

BOBJS		=	$(addprefix obj/, $(BSRCS:.c=.o))

BOBJS_DIRS	=	$(sort $(dir $(BOBJS)))

HEADER		=	.

LIBFT_PATH	= ./libft

LIBFT		= $(LIBFT_PATH)/libft.a

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(NAME): $(LIBFT) $(OBJS_DIRS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lft -L$(LIBFT_PATH) -o $(NAME)

bonus:	$(LIBFT) $(BOBJS_DIRS) $(BOBJS)
	$(CC) $(CFLAGS) $(BOBJS) -lft -L$(LIBFT_PATH) -o checker

obj/%.o: %.c
	$(CC) $(CFLAGS) -c $^ -lft -L$(LIBFT_PATH) -I $(HEADER) -I $(LIBFT_PATH)/header -o $@

$(sort $(BOBJS_DIRS) $(OBJS_DIRS)):
	@mkdir -p $@

clean:
	make -C $(LIBFT_PATH) clean
	rm -rf obj

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -rf $(NAME)
	rm -rf checker

re: fclean all

.PHONY: bonus all clean fclean re bonus

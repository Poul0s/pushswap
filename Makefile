# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psalame <psalame@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 11:02:12 by psalame           #+#    #+#              #
#    Updated: 2023/11/25 18:29:59 by psalame          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -g

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
				sort/algorithm/big_sort/get_best_mouvment.c \
				sort/algorithm/big_sort/cost_calcul.c \
				sort/algorithm/big_sort/extreme_value.c \
				utils/ft_isnumber.c \
				utils/arguments.c \
				push_swap.c \
				utils/error.c \
				utils/min_max.c

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
				utils/arguments.c \
				utils/ft_isnumber.c \
				utils/min_max.c \
				checker_bonus/exec_action_bonus.c \
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

bonus:	checker

checker: $(LIBFT) $(BOBJS_DIRS) $(BOBJS)
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

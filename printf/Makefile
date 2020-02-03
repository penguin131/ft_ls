# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/21 14:49:30 by smight            #+#    #+#              #
#    Updated: 2019/05/31 11:26:02 by rsumner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

LIBFT = ../libft

DIR_S = src

DIR_O = temp

SOURCES = doubles.c \
		  long_math.c \
		  upgrade.c \
		  check_if_param.c \
		  func_common.c \
		  func_cs.c \
		  get_data.c \
		  sort_data.c \
		  treat_data.c \
		  flags_handle.c\
		  func_xou.c\
		  func_dpb.c\
		  colors.c \
		  upgrade2.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp ../libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "printf OK!"

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	@$(CC) $(FLAGS) -I $(DIR_S) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

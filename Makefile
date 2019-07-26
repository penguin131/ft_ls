NAME = ft_ls

FILES = main.c

S_DIR = src/

O_DIR = obj/

SRC = $(addprefix $(S_DIR), $(FILES))

OBJ = $(addprefix $(O_DIR), $(FILES:.c=.o))

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJ)
	make -C libft/
	gcc -o $(NAME) $(OBJ) -Iinc -L libft libft/libftprintf.a

$(O_DIR)%.o:$(S_DIR)%.c
	mkdir -p $(O_DIR)
	gcc $(FLAGS) -Iinc -o $@ -c $<

clean:
	make clean -C libft/
	rm -rf $(O_DIR)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all

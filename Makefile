NAME = ft_ls

FILES = main.c add_files.c handle_error.c print_files.c read_folders.c sorting.c read_flags.c

S_DIR = src/

O_DIR = obj/

SRC = $(addprefix $(S_DIR), $(FILES))

OBJ = $(addprefix $(O_DIR), $(FILES:.c=.o))

FLAGS =

LIB = libft/libft.a

PRINTF = printf/libftprintf.a

all: $(NAME) libft/ printf/

$(NAME) : $(OBJ)
	@make -C libft/
	@make -C printf/
	@gcc -o $(NAME) $(FLAGS) $(OBJ) -Iinc $(LIB) $(PRINTF)

$(O_DIR)%.o:$(S_DIR)%.c inc/
	@mkdir -p $(O_DIR)
	@gcc $(FLAGS) -Iinc -o $@ -c $<

clean:
	@make clean -C libft/
	@make clean -C printf/
	@rm -rf $(O_DIR)

fclean: clean
	@make fclean -C libft/
	@make fclean -C printf/
	@rm -f $(NAME)

re: fclean all

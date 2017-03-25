
CC = gcc -Wall -Wextra -Werror


NAME = filler

FT_LS_SRC = find_place.c util.c algo.c wave_algo.c parse_info.c distance_watcher.c

OBJECTS = $(subst .c,.o,$(FT_LS_SRC))

$(NAME): $(OBJECTS)
	@make -C libft/
	gcc $(OBJECTS) -o $(NAME) libft/libftprintf.a


all: $(NAME)

clean: 
	@make -C libft/ clean
	rm -rf $(OBJECTS)

fclean: clean
	@make -C libft/ fclean
	rm -rf $(NAME) $(OBJECTS)

re: fclean all
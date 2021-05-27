CC = gcc
NAME = ft_printf
FLAGS += -g -Wall -Wextra -Werror

SRC =	ft_printf.c \
		libft_utils.c \
		outChar.c \
		outStr.c

FLAG_C = main_c.c
FLAG_S = main_s.c

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) $(SRC) $(FLAG_C) -o $(NAME)
	@./$(NAME)

c:
	@$(CC) $(FLAGS) $(SRC) $(FLAG_C) -o $(NAME)
	@./$(NAME)
s:
	@$(CC) $(FLAGS) $(SRC) $(FLAG_S) -o $(NAME)
	@./$(NAME)
test:
	@$(CC) $(FLAGS) $(SRC) main_test.c -o $(NAME)
	@./$(NAME)

clean:
	@rm -rf $(NAME)

re: clean all

NAME = libftprintf.a

LIBFT = libft

CC = gcc
FLAGS += -g -Wall -Wextra -Werror
AR	= ar crs

HEADER = include

SRC_PATH = src
OBJS_PATH = objs

SOURCES =	ft_printf.c \
			parseFlags.c \
			parseFormat.c \
			parseTab.c \
			checks.c \
			alignment.c \
			outChar.c \
			outStr.c \
			outInt.c \
			outPointer.c \
			outHexa.c \
			outPercent.c

SRC = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS = $(addprefix $(OBJS_PATH)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@${AR} ${NAME} ${OBJS}
	@ranlib $(NAME)

$(OBJS_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p objs
	@$(CC) $(FLAGS) -g -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_OBJS)
	@make clean -C $(LIBFT)

fclean:	clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: clean all

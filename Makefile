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

BUILD_PRINT = @echo "\033[1;96m		 [PRINTF]\033 \033[38;5;82mBuilding $<"
CLEAN_O = @echo "\033[38;5;246mObject files removed! [PRINTF]\033[0m"
CLEAN_A = @echo "\033[38;5;246mExecutable removed! [PRINTF]\033[0m"

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@${AR} ${NAME} ${OBJS}
	@ranlib $(NAME)

$(OBJS_PATH)/%.o: $(SRC_PATH)/%.c
	$(BUILD_PRINT)
	@mkdir -p objs
	@$(CC) $(FLAGS) -g -I $(HEADER) -o $@ -c $<

clean:
	@rm -rf $(OBJS_PATH)
	@make clean -C $(LIBFT)
	$(CLEAN_O)

fclean:	clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
	$(CLEAN_A)

re: clean all

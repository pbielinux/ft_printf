NAME = libftprintf.a

CC = gcc
FLAGS += -g -Wall -Wextra -Werror

AR	= ar crs

SRCS_PATH = srcs/
SRC =	$(SRCS_PATH)ft_printf.c \
		$(SRCS_PATH)libft_utils.c \
		$(SRCS_PATH)parseFormat.c \
		$(SRCS_PATH)parseFlags.c \
		$(SRCS_PATH)parseTab.c \
		$(SRCS_PATH)checks.c \
		$(SRCS_PATH)alignment.c \
		$(SRCS_PATH)outChar.c \
		$(SRCS_PATH)outStr.c \
		$(SRCS_PATH)outInt.c \
		$(SRCS_PATH)outPointer.c \
		$(SRCS_PATH)outHexa.c \
		$(SRCS_PATH)outPercent.c

SRCS_OBJS	= ${SRC:.c=.o}

all: $(NAME)

$(NAME): ${SRCS_OBJS}
	@${AR} ${NAME} ${SRCS_OBJS}

c:
	@$(CC) $(FLAGS) $(SRC) main_c.c -o $(NAME)
	@./$(NAME)
s:
	@$(CC) $(FLAGS) $(SRC) main_s.c -o $(NAME)
	@./$(NAME)
test:
	@$(CC) $(FLAGS) $(SRC) main_test.c -o $(NAME)
	@./$(NAME)

clean:
	@rm -f ${SRCS_OBJS}

fclean:	clean
	@rm -f $(NAME)

re: clean all

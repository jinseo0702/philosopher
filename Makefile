CC = clang
CFLAGS = -Wall -Wextra -Werror -g -pthread
RM = rm -rf

SRC = src/init.c \
src/main.c \
src/philo_utils.c \
src/print_text.c \
src/routin.c \

OBJS = $(SRC:.c=.o)
NAME = philo

all : $(NAME)

$(NAME): $(OBJS)
#@$(CC) $(CFLAG) $(OBJS) -o $(NAME) -fsanitize=thread
	@$(CC) $(CFLAG) $(OBJS) -o $(NAME)

clean :
	@$(RM) $(OBJS)

fclean :
	@$(RM) $(OBJS) $(NAME)

re : 
	@make fclean
	@make all

.PHONY: all clean fclean re
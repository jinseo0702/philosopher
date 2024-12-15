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
TH = ph_th
LE = leak

all : $(NAME)

debug_th : $(TH)

debug_le : $(LE)

$(NAME): $(OBJS)
	@$(CC) $(CFLAG) $(OBJS) -o $(NAME)

$(TH): $(OBJS)
	@$(CC) $(CFLAG) $(OBJS) -o $(TH) -fsanitize=thread

$(LE): $(OBJS)
	@$(CC) $(CFLAG) $(OBJS) -o $(LE) -fsanitize=address

clean :
	@$(RM) $(OBJS)

fclean :
	@$(RM) $(OBJS) $(NAME) $(TH) $(LE)

re : 
	@make fclean
	@make all

.PHONY: all clean fclean re
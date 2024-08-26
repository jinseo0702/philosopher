CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

SRC = use_thread.c

OBJS = $(.c=.o)

NAME = lab

all : $(NAME)

clean :
	@$(RM) $(OBJS)

fclean :
	@$(RM) $(OBJS) $(NAME)

re : 
	@make fclean
	@make all

.PHONY: all clean fclean re
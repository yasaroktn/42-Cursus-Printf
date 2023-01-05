NAME = libftprintf.a

SRC = $(wildcard *.c)

OBJS = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all fclean re clean
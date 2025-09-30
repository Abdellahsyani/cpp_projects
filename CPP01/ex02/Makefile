NAME = ref

CC = c++
FLAG = -Wall -Wextra -Werror

SRC = ...

OBJ = $(SRC%.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAG) $(SRC) -o $(NAME)

%.o : %.c
	$(CC) $(FLAG) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

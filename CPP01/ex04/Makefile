NAME = sed

CC = c++

FLAG = -Wall -Wextra -Werror

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAG) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAG) -cpp $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rn -f $(NAME)

re: fclean all

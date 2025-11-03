NAME = account

CC = c++ -std=c++98
FLAG = -Wall -Wextra -Werror

SRC = tests.cpp Account.cpp

OBJ = $(SRC:.cpp=.o)
	

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAG) $(SRC) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAG) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

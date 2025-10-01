NAME = zombie

CC = c++
FLAG = -Wall -Wextra -Werror

SRC = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp 

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

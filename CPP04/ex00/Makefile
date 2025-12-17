NAME = animal

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

HDR = Animal.hpp Dog.hpp Cat.hpp
SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp

all: $(NAME)

$(NAME): $(SRC) $(HDR)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

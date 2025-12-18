NAME = clap 

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

HDR = ClapTrap.hpp
SRC = main.cpp ClapTrap.cpp

all: $(NAME)

$(NAME): $(SRC) $(HDR)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

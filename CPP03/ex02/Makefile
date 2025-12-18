NAME = Frag 

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

HDR = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp
SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

all: $(NAME)

$(NAME): $(SRC) $(HDR)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

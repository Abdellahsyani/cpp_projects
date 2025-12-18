NAME = diamond 

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

HDR = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp
SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

NAME = Bureaucrat

CXX = c++
CXXFLAGS = -g -Wall -Wextra -Werror -std=c++98

HDR = Bureaucrat.hpp Form.hpp
SRC = main.cpp Bureaucrat.cpp Form.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HDR)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HDR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME) $(OBJ)

re: fclean all

.PHONY: all clean fclean re

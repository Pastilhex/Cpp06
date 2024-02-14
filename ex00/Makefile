NAME = Converter
SRC = main.cpp  ScalarConverter.cpp
OBJ = $(SRC:.cpp=.o)
CXX = c++
FLAGSXX = -Wall -Werror -Wextra -std=c++98 -g

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(FLAGSXX) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(FLAGSXX) -c $< -o $@

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(OBJ)

re: fclean all

.PHONY: all re fclean clean
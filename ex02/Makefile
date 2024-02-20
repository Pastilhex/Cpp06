NAME = identify
SRC = main.cpp Base.cpp
OBJ = $(SRC:.cpp=.o)
CXX = c++
FLAGSCXX = -Wall -Wextra -Werror -g -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(FLAGSCXX) $^ -o $@

%.o: %.cpp
	$(CXX) $(FLAGSCXX) -c $< -o $@

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(OBJ)

re: fclean all

.PHONY: all re clean fclean
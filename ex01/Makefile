NAME = serialize
SRC = main.cpp Serializer.cpp
OBJ = $(SRC:.cpp=.o)
CXX = c++
FLAGSXX = -Wall -Wextra -Werror -g -std=c++98

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

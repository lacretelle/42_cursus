NAME = replace
SRC = ReplaceFile.cpp main.cpp
INC = ReplaceFile.hpp

CC = clang++
OBJ = $(SRC:.cpp=.o)
FLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME): $(SRC) $(INC) Makefile
	$(CC) -I $(INC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) 

re:	fclean all

.PHONY: all clean fclean re

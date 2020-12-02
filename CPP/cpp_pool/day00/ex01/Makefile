NAME = phonebook
SRC = Phonebook.class.cpp Contact.class.cpp  main.cpp
INC = Phonebook.class.hpp Contact.class.hpp

CC = clang++
OBJ = $(SRC:.cpp=.o)
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(SRC) $(INC) Makefile
	$(CC) -I Phonebook.class.hpp $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) 

re:	fclean all

.PHONY: all clean fclean re

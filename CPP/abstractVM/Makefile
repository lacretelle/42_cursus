NAME = avm
SRC = main.cpp lexer.cpp read.cpp token.cpp parser.cpp abstractVM.cpp exception.cpp OperandFactory.cpp OperandTemp.cpp
# INC = 
# IOperand.hpp eOperandType.hpp OperandFactory.hpp

CC = clang++
OBJ = $(SRC:.cpp=.o)
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(SRC) Makefile #$(INC) before makefile + I $(INC) after cc
	$(CC) $(FLAGS) $(SRC) -o $(NAME) 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) 

re:	fclean all

.PHONY: all clean fclean re

##
## ARP SPOOFING
##
## Makefile
##

# Compilation
CC		=	gcc
CFLAGS	=	-W -Werror -Wextra -Wall -I$(INCLUDE_DIRECTORY)	\

BINARY_NAME							=	myARPspoof
TEST_BINARY_NAME					=	myARPspoof_test

# Object files
OBJS		=	$(SRC:.c=.o)
MAIN_OBJ	=	$(MAIN_SRC:.c=.o)
TEST_OBJS	=	$(TEST_SRC:.c=.o)

# Criterion flags
CRITERION	=	-lcriterion -lgcov --coverage

# Static library flags
STATIC_LIB_FLAG		=	-L$(LIBRARY_PATH)

# Paths
SRC_DIRECTORY					=	./src
TEST_DIRECTORY					=	./tests
INCLUDE_DIRECTORY				=	./include
LIBRARY_PATH					=	./lib

# Source files
SRC			=										\

# Main file
MAIN_SRC	=	$(SRC_DIRECTORY)/main.c				\

# Test files
TEST_SRC	=										\

# Rules
all: $(BINARY_NAME)

$(BINARY_NAME): $(OBJS) $(MAIN_OBJ)
	$(CC) $(OBJS) $(MAIN_OBJ) -o $(BINARY_NAME) $(STATIC_LIB_FLAG)

debug:
	$(CC) -g3 $(SRC) $(MAIN_SRC) -o $(BINARY_NAME) $(STATIC_LIB_FLAG) -I$(INCLUDE_DIRECTORY)

tests_run: tests_compile
	./$(TEST_BINARY_NAME) -j1 --xml=./report/core.xml

tests_compile:
	$(CC) $(SRC) $(TEST_SRC) -o $(TEST_BINARY_NAME) $(STATIC_LIB_FLAG) $(CRITERION) -I$(INCLUDE_DIRECTORY)

clean:
	rm -f $(OBJS) $(MAIN_OBJ) $(TEST_OBJS)
	rm -f *.gcda
	rm -f *.gcno

fclean: clean
	rm -f $(TEST_BINARY_NAME) $(BINARY_NAME)

re: fclean all
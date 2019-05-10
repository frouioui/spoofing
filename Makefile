##
## ARP SPOOFING
##
##
##

# Compilation
CC		=	gcc
CFLAGS	=	-W -Werror -Wextra -Wall -I$(INCLUDE_DIRECTORY)					\
									-I$(LIBRARY_ERROR_INCLUDE)				\

# FTP server
BINARY_NAME							=	myARPspoof
TEST_BINARY_NAME					=	myARPspoof_test

# String parsing library
LIBRARY_ERROR_NAME			=	liberror.a
LIBRARY_ERROR_TEST_NAME		=	error_test

# Object files
OBJS		=	$(SRC:.c=.o)
MAIN_OBJ	=	$(MAIN_SRC:.c=.o)
TEST_OBJS	=	$(TEST_SRC:.c=.o)

# Criterion flags
CRITERION	=	-lcriterion -lgcov --coverage

# Static library flags
STATIC_LIB_FLAG		=	-L$(LIBRARY_PATH) -lerror

# Paths
SRC_DIRECTORY					=	./src
TEST_DIRECTORY					=	./tests
INCLUDE_DIRECTORY				=	./include
LIBRARY_PATH					=	./lib

# Include path static libraries
LIBRARY_ERROR_INCLUDE	=	$(LIBRARY_PATH)/error/include

# Source files
SRC			=	$(SRC_DIRECTORY)/argument/get_args.c				\
				$(SRC_DIRECTORY)/arp/arp_destroy.c					\
				$(SRC_DIRECTORY)/arp/arp_fill.c						\
				$(SRC_DIRECTORY)/arp/arp_init.c						\
				$(SRC_DIRECTORY)/packet/packet_configure_arp.c		\
				$(SRC_DIRECTORY)/packet/packet_configure_ethernet.c	\
				$(SRC_DIRECTORY)/packet/packet_init.c

# Main file
MAIN_SRC	=	$(SRC_DIRECTORY)/main.c		\

# Test files
TEST_SRC	=	\

# Rules
all: $(BINARY_NAME)

$(BINARY_NAME): compile_library $(OBJS) $(MAIN_OBJ)
	$(CC) $(OBJS) $(MAIN_OBJ) -o $(BINARY_NAME) $(STATIC_LIB_FLAG)

debug: compile_library_debug
	$(CC) -g3 $(SRC) $(MAIN_SRC) -o $(BINARY_NAME) $(STATIC_LIB_FLAG) -I$(INCLUDE_DIRECTORY) -I$(LIBRARY_ERROR_INCLUDE)

compile_library:
	make -C $(LIBRARY_PATH)

compile_library_debug:
	make debug -C $(LIBRARY_PATH)

tests_run: tests_compile
	# ./$(TEST_BINARY_NAME) -j1 --always-succeed --xml=report/core.xml
	./$(LIBRARY_PATH)/$(LIBRARY_ERROR_TEST_NAME) -j1 --always-succeed --xml=report/error.xml

tests_compile: compile_library
	make tests_compile -C $(LIBRARY_PATH) ; cp $(LIBRARY_PATH)/$(LIBRARY_ERROR_TEST_NAME) .
	# $(CC) $(SRC) $(TEST_SRC) -o $(TEST_BINARY_NAME) $(STATIC_LIB_FLAG) $(CRITERION) -I$(INCLUDE_DIRECTORY) -I$(LIBRARY_ERROR_INCLUDE)

clean:
	make clean -C $(LIBRARY_PATH)
	rm -f $(OBJS) $(MAIN_OBJ) $(TEST_OBJS)
	rm -f *.gcda
	rm -f *.gcno

fclean: clean
	make fclean -C $(LIBRARY_PATH)
	rm -f $(TEST_BINARY_NAME) $(BINARY_NAME) $(LIBRARY_ERROR_TEST_NAME)

re: fclean all
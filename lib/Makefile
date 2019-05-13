##
## ARP SPOOFING
##
##

# Paths
ERROR_DIRECTORY		=	./error
ERROR_LIB_NAME		=	liberror.a
ERROR_TEST_NAME		=	error_test


# Rules
all:
	make -C $(ERROR_DIRECTORY) ; cp $(ERROR_DIRECTORY)/$(ERROR_LIB_NAME) .

debug:
	make CC="gcc -g3" -C $(ERROR_DIRECTORY) ; cp $(ERROR_DIRECTORY)/$(ERROR_LIB_NAME) .

tests_run: tests_compile
	./$(ERROR_TEST_NAME) -j1

tests_compile:
	make tests_compile -C $(ERROR_DIRECTORY) ; cp $(ERROR_DIRECTORY)/$(ERROR_TEST_NAME) .

clean:
	make clean -C $(ERROR_DIRECTORY)

fclean: clean
	make fclean -C $(ERROR_DIRECTORY)
	rm -f	$(ERROR_LIB_NAME) $(ERROR_TEST_NAME)

re: fclean all
CC = cc
CFLAGS = -Wall
NAME = libfuck.so
LINK_FLAG = ./libfuck.so 

lib: arrays
	$(CC) -shared build/array.o -o $(NAME)

arrays:
	$(CC) -c $(CFLAGS) src/arrays/array.c -o build/array.o

example_array: lib
	$(CC) $(CFLAGS) $(LINK_FLAG) examples/array.c -o example_array.a

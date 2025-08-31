CC = cc
CFLAGS = -Wall
NAME = libfuck.so
LINK_FLAG = ./libfuck.so 


lib_full: arrays flags
	$(CC) -shared build/*.o -o $(NAME)

lib: arrays builder
	$(CC) -shared build/*.o -o $(NAME)

arrays:
	$(CC) -c $(CFLAGS) src/arrays/array.c -o build/array.o

flags:
	$(CC) -c $(CFLAGS) src/flags/flags.c -o build/flags.o

example_array: lib
	$(CC) $(CFLAGS) $(LINK_FLAG) examples/example_array.c -o example.a

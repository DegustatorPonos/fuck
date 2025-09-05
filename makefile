CC = cc
CFLAGS = -Wall
NAME = libfuck.so
LINK_FLAG = ./libfuck.so 

fuck_builder: lib_full
	$(CC) $(CFLAGS) $(LINK_FLAG) builder/main.c -o ./builder.a

arrays:
	$(CC) -c $(CFLAGS) src/arrays/array.c -o build/array.o

lists:
	$(CC) -c $(CFLAGS) src/arrays/lists.c -o build/lists.o

flags:
	$(CC) -c $(CFLAGS) src/flags/flags.c -o build/flags.o

lib_full: arrays flags lists
	$(CC) $(CFLAGS) -shared build/*.o -o $(NAME)

example_array: lib_full
	$(CC) $(CFLAGS) examples/example_array.c $(LINK_FLAG) -o example.a

example_flags: lib_full
	$(CC) $(CFLAGS) examples/example_flags.c $(LINK_FLAG) -o example.a

example_lists: lib_full
	$(CC) $(CFLAGS) examples/example_lists.c $(LINK_FLAG) -o example.a

#$@: gets the name of the Makefile rule
#$^: gets all the prerequisites
#$<: gets the first prerequisite

CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -Wvla -pedantic
CPPFLAGS = -fsanitize=address -g3
LDFLAGS =
LIBNAME = libstream.a
OBJ = src/lbs_fdopen.c
EXE = main

library: $(OBJ)
	ar -rc $(LIBNAME) $^

%.o: %.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $^

main: src/main.o $(OBJ)
	$(CC) $(CFLAGS) -o $(EXE) $^ $(LDFLAGS)

debug: LDFLAGS += -g3 -fsanitize=address
debug: main

clean:
	$(RM) src/*.o $(EXE) $(LIBNAME)

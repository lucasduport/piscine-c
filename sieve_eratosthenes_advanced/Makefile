#$@: gets the name of the Makefile rule
#$^: gets all the prerequisites
#$<: gets the first prerequisite

CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -Wvla -pedantic
CPPFLAGS = -fsanitize=address -g3
LDFLAGS =
OBJ = sieve.o

sieve.o: sieve.c
	@$(CC) $(CFLAGS) -c $^

main: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

debug: LDFLAGS += -g3 -fsanitize=address
debug: main

clean:
	$(RM) *.o main

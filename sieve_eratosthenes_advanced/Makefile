CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -Wvla -pedantic
LDFLAGS =
OBJ = sieve_eratosthenes_advanced.o
BIN = main

all: $(OBJ)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) 

debug: LDFLAGS += -g3 -fsanitize=address
debug: $(OBJ)
	$(CC) $(LDFLAGS) $^

clean:
	$(RM) $(OBJ) a.out

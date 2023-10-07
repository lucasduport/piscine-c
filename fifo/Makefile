#$@: gets the name of the Makefile rule
#$^: gets all the prerequisites
#$<: gets the first prerequisite

CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -Wvla -pedantic
CPPFLAGS = -fsanitize=address -g
LDFLAGS =
OBJ = fifo_access.o \
	  fifo_setup_destroy.o

library: $(OBJ)
	ar -rc libfifo.a $^

%.o: %.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $^

main: main.o $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

debug: LDFLAGS += -g3 -fsanitize=address
debug: main

clean:
	$(RM) *.o main libfifo.a

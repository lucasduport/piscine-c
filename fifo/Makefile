#$@: gets the name of the Makefile rule
#$^: gets all the prerequisites
#$<: gets the first prerequisite

CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -Wvla -pedantic
LDFLAGS =
OBJ = fifo_access.o fifo_setup_destroy.o

library: $(OBJ)
	ar -rc libfifo.a $^

debug: LDFLAGS += -g3 -fsanitize=address
debug: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)


clean:
	$(RM) $(OBJ) debug libfifo.a

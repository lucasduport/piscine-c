#$@: gets the name of the Makefile rule
#$^: gets all the prerequisites
#$<: gets the first prerequisite

CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -Wvla -pedantic
CPPFLAGS = -fsanitize=address -g3
LDFLAGS =
LIBNAME = libvector.a 
OBJ = vector_manage.o \
	  vector_op.o

library: $(OBJ)
	ar -rc $(LIBNAME) $^

%.o: %.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $^

main: main.o $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

debug: LDFLAGS += -g3 -fsanitize=address
debug: main

clean:
	$(RM) *.o main $(LIBNAME)

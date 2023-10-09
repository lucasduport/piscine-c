#$@: gets the name of the Makefile rule
#$^: gets all the prerequisites
#$<: gets the first prerequisite
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -Wvla -pedantic
CPPFLAGS = -fsanitize=address -g3
LIBNAME = libbinary_tree.a
EXE = main
LDFLAGS =
OBJ = binary_tree.o

library: $(OBJ)
	ar -rc $(LIBNAME) $^

%.o: %.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $^

$(EXE): main.o $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

debug: LDFLAGS += -g3 -fsanitize=address
debug: $(EXE)

clean:
	$(RM) *.o $(EXE) $(LIBNAME)

CC=gcc
CFLAGS=-I.
DEPS = list.h
OBJ = list.o list_test.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

list: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
CC = gcc
CFLAGS = -Wall
DEPS = quadratic.h
OBJ = quadratic.o main.o
LIBS = -lm

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

quadratic: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -rf *.o

TARGET = hello

CC = gcc

CFLAGS = -Wall -g

all: $(TARGET)

hello.o: hello.c # generate hello.o need hello.c
	$(CC) $(CFLAGS) -c hello.c

$(TARGET): hello.o # generate hello need hello.o
	$(CC) -o $(TARGET) hello.o

# $(TARGET): hello.c
# 	$(CC) $(CFLAGS) -o $(TARGET) hello.c

clean:
	rm -f $(TARGET) hello.o

run:
	./$(TARGET)

valgrind:
	valgrind --leak-check=full ./$(TARGET)
TARGET = binary

CC = gcc

CFLAGS = -Wall -g

all: $(TARGET)

classic_application: classic_application.c
	$(CC) $(CFLAGS) -o classic_application classic_application.c

classic_application_run: classic_application
	./classic_application

hex_binary: hex_binary.c
	$(CC) $(CFLAGS) -o hex_binary hex_binary.c

hex_binary_run: hex_binary
	./hex_binary

clean:
	rm -f $(TARGET) classic_application hex_binary
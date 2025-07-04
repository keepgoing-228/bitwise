# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g -std=c99
LDFLAGS =

# Targets
TARGETS = classic_application hex_binary

# Default target
.PHONY: all
all: $(TARGETS)

# Build targets with proper dependencies
classic_application: classic_application.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

hex_binary: hex_binary.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

# Run targets
.PHONY: run-classic run-hex
run-classic: classic_application
	./classic_application

run-hex: hex_binary
	./hex_binary

# Development targets
.PHONY: debug
debug: CFLAGS += -DDEBUG -O0 -fno-omit-frame-pointer
debug: $(TARGETS)

.PHONY: release
release: CFLAGS += -O2 -DNDEBUG
release: $(TARGETS)

# Valgrind targets for memory leak detection
.PHONY: valgrind-classic valgrind-hex
valgrind-classic: debug
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-classic.log ./classic_application

valgrind-hex: debug
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-hex.log ./hex_binary

# Utility targets
.PHONY: clean
clean:
	rm -f $(TARGETS) *.o valgrind-*.log

.PHONY: help
help:
	@echo "Available targets:"
	@echo "  all              - Build all executables"
	@echo "  run-classic      - Build and run classic_application"
	@echo "  run-hex          - Build and run hex_binary"
	@echo "  debug            - Build with debug flags"
	@echo "  release          - Build with optimization flags"
	@echo "  valgrind-classic - Run classic_application with valgrind"
	@echo "  valgrind-hex     - Run hex_binary with valgrind"
	@echo "  clean            - Remove all generated files"
	@echo "  help             - Show this help message"
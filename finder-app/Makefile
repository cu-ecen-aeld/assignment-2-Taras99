# Variables for cross-compilation
CC := $(CROSS_COMPILE)gcc
CFLAGS := -Wall -Werror -g
TARGET := writer
SRCS := writer.c
OBJS := $(SRCS:.c=.o)

# Default target to build the application
.PHONY: all
all: $(TARGET)

# Rule to build the writer application
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target to remove generated files
.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)

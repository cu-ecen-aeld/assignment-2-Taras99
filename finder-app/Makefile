CC = $(CROSS_COMPILE)gcc
CFLAGS = -Wall -Wextra -Werror -g
TARGET = writer

.PHONY: all clean

all: $(TARGET)

$(TARGET): writer.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET) *.o


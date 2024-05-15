CC = gcc
CFLAGS = -Iinclude -std=c99

SRC = src/main.c src/student.c src/utils.c
OBJ = $(SRC:.c=.o)
TARGET = student_management_system

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean

CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -g

# Diretórios
SRC_DIR = src
OBJ_DIR = build
INC_DIR = include

# Arquivos fonte
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Nome do executável
TARGET = my_program

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)

.PHONY: all clean

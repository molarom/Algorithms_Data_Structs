SRC_DIR := src
OBJ_DIR := obj
BUILD_DIR := build

SOURCES := $(wildcard $(SRC_DIR)/*.c)
OBJECTS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SOURCES))

EXECUTABLE := sorter

CC := gcc
CFLAGS := -Wall -Wextra -pedantic -Wno-missing-field-initializers

.PHONY: all clean

all: $(BUILD_DIR)/$(EXECUTABLE)

$(BUILD_DIR)/$(EXECUTABLE): $(OBJECTS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@ 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR) $(BUILD_DIR):
	mkdir $@

clean:
	rm -rf $(OBJ_DIR) $(BUILD_DIR)

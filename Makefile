SRC_DIR := src
OBJ_DIR := obj
BUILD_DIR := build

SOURCES := $(wildcard $(SRC_DIR)/*.c)
OBJECTS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SOURCES))

EXECUTABLE := sorter

CC := gcc
CFLAGS := -g -Wall -Wextra -pedantic -Wno-missing-field-initializers


.PHONY: help
help: ## Display this help.
	@awk 'BEGIN {FS = ":.*##"; printf "\nUsage:\n  make \033[36m<target>\033[0m\n"} /^[a-zA-Z_0-9-]+:.*?##/ { printf "  \033[36m%-15s\033[0m %s\n", $$1, $$2 } /^##@/ { printf "\n\033[1m%s\033[0m\n", substr($$0, 5) } ' $(MAKEFILE_LIST)

##@ Building

.PHONY: all
all: ## Build the executable
	$(BUILD_DIR)/$(EXECUTABLE)

$(BUILD_DIR)/$(EXECUTABLE): $(OBJECTS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@ 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR) $(BUILD_DIR):
	mkdir $@

##@ Clean

.PHONY: clean
clean: ## Cleanup object files and binary.
	rm -rf $(OBJ_DIR) $(BUILD_DIR)


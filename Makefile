CC=clang
CFLAGS=-Wall -Wextra -Werror -fsanitize=address -g -std=c11

SRC_DIR=src
BUILD_DIR=builds

SOURCES=$(wildcard $(SRC_DIR)/*.c)
TARGETS=$(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%,$(SOURCES))

all: $(TARGETS)

$(BUILD_DIR)/%: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
CC = gcc
CFLAGS = -std=gnu23 -Wall -Wextra -Werror -Wpedantic -Iinclude
SRC = main.c src/read_and_validate.c src/stringy.c
OUT = calculator

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
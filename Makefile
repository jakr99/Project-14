CC = gcc
CFLAGS = -Wall -Wextra

PROBLEM1_SRC = problem1.c
PROBLEM2_SRC = problem2.c

PROBLEM1_OUT = problem1
PROBLEM2_OUT = problem2

all: problem1 problem2

problem1: $(PROBLEM1_SRC)
	$(CC) $(CFLAGS) -o $(PROBLEM1_OUT) $<

problem2: $(PROBLEM2_SRC)
	$(CC) $(CFLAGS) -o $(PROBLEM2_OUT) $<

sanitized: CFLAGS += -fsanitize=address -fno-omit-frame-pointer
sanitized: all

clean:
	rm -f $(PROBLEM1_OUT) $(PROBLEM2_OUT)

.PHONY: all sanitized clean

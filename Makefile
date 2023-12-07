OUTPUT := bin
SRC_DIR := ./src

CC := gcc
ERRFLAGS := -Wall -Wextra -Wpedantic -Werror
OPT := -O0
DEPFLAGS := -MP -MD
LIBS := -lm -lSDL2
CFLAGS := -I/usr/include/SDL2 -D_REENTRANT -std=c99 $(ERRFLAGS) -g $(OPT) $(DEPFLAGS) $(LIBS)

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJECTS := $(patsubst %.c, %.o, $(SRCS))
DEPFILES := $(patsubst %.c, %.d, $(SRCS))

all: $(OUTPUT)

$(OUTPUT): $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OUTPUT) $(OBJECTS) $(DEPFILES)

package: clean
	7z a -t7z -m0=lzma -mx=9 -mfb=64 -md=32m -ms=on proj.7z src Makefile

.PHONY: all clean package

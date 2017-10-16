BIN = main

CFLAGS = -g -Wall
LDFLAGS =
LDLIBS =

SOURCES = $(wildcard *.c)
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))

.PHONY: style clean

$(BIN): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)

style:
	astyle -A3s4SpHk3jn *.c *.h

clean:
	rm -f $(BIN) $(OBJECTS)

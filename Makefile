CC=g++
CFLAGS=-c -Wall
LDFLAGS=-lncurses
SOURCES=main.cpp player.cpp map.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=roguelike_game

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)


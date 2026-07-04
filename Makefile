CC = g++

CFLAGS = -Wall -Wextra -Iinclude

LDFLAGS = -lraylib

SRC = $(wildcard src/*.cpp)

TARGET = simulation

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

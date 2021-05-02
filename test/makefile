CC = gcc

INCLUDES = GameOfLife.h

CFLAGS = -Wall

LIBS = -lSDL2 -lGL

SRCS = GameOfLife.c Test.c

TARGET = GameOfLifeTest

$(TARGET): $(SRCS) $(INCLUDES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS) $(LIBS)

clean:
	rm $(TARGET)

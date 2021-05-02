CC = gcc

INCLUDES = main.h GameOfLife.h

CFLAGS = -Wall

LIBS = -lSDL2 -lGL

SRCS = main.c GameOfLife.c

TARGET = GameOfLife

$(TARGET): $(SRCS) $(INCLUDES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS) $(LIBS)

clean:
	rm $(TARGET)

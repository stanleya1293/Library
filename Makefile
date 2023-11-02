CC = g++
CFLAGS = -g -Wall -Wextra
TARGET = library

all: $(TARGET)

$(TARGET): main.o library.o
	$(CC) main.o library.o -o $(TARGET)

main.o: main.cpp Library.h
	$(CC) $(CFLAGS) main.cpp -o main.o

library.o: Library.cpp Library.h
	$(CC) $(CFLAGS) Library.cpp -o library.o

clean:
	$(RM) library *.o *~

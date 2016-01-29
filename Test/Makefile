CC=g++
CFLAGS=-Wall
LDFLAGS=-lcppunit
SOURCES=TestArkanoid.cpp ../Arkanoid.cpp MockMatrix.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Test

all:
	$(CC) $(CFLAGS) $(SOURCES) $(LDFLAGS) -o $(EXECUTABLE) 
	
clean:
	rm *.o $(EXECUTABLE)

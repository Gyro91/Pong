CC=g++
CFLAGS=-Wall
LDFLAGS=-lcppunit
SOURCES=TestPong.cpp ../Pong.cpp MockMatrix.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=TestPong

all:
	$(CC) $(CFLAGS) $(SOURCES) $(LDFLAGS) -o $(EXECUTABLE) 
	
clean:
	rm *.o $(EXECUTABLE)

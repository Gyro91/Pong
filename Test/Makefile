CC=g++
CFLAGS=-Wall -std=c++11
LDFLAGS=-lcppunit
SOURCES=TestPong.cpp ../Pong.cpp MockMatrix.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=TestPong

all:
	$(CC) $(CFLAGS) $(SOURCES) $(LDFLAGS) -o $(EXECUTABLE) 
	
clean:
	rm *.o $(EXECUTABLE)

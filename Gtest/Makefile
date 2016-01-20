GTEST_DIR=googletest-master/googletest
GMOCK_DIR=googletest-master/googlemock
CC=g++

all:
	g++ -isystem ${GTEST_DIR}/include -isystem ${GMOCK_DIR}/include \
    -pthread buttontest.cpp libgmock.a -o your_test

all2:
	 g++ -I $(GTEST_DIR)/include test.cpp libgtest.a  -lpthread -o test
clean:
	rm *o 

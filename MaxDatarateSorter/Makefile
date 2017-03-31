# -L looks for libs in a directory
# -l looks for a specific library (e.g. -lcppunit)
LIBRARIES = -L/usr/local/lib -L/usr/lib -l:libcppunit.so
INCLUDE = -I./
CC = g++ -std=c++11 -Wall -pedantic
NAME = scheduler

all: *.cpp *.hpp
	$(CC) *.cpp -o $(NAME) $(INCLUDE) $(LIBRARIES)

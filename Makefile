CC=g++
CFLAGS= -c -Wall

output: main.o
	$(CC) main.o -o output

main.o: target.o radar.o main.cpp
	$(CC) $(CFLAGS) main.cpp

radar.o: radar.cpp radar.hpp
	$(CC) $(CFLAGS) radar.cpp

target.o: target.cpp target.hpp
	$(CC) $(CFLAGS) target.cpp

clean: 
	rm -r *.o output

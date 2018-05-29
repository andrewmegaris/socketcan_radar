CC      := g++
CFLAGS  := -c -Wall
BIN     := bin
SRC     := src
INC     := include
EXA_DIR := examples

scan_and_print: scan_and_print.o
	$(CC) scan_and_print.o -o $(BIN)/scan_and_print

scan_and_print.o: target.o radar.o $(EXA_DIR)/scan_and_print.cpp
	$(CC) $(CFLAGS) $(EXA_DIR)/scan_and_print.cpp

radar.o: $(SRC)/radar.cpp $(INC)/radar.hpp
	$(CC) $(CFLAGS) $(SRC)/radar.cpp

target.o: $(SRC)/target.cpp $(INC)/target.hpp
	$(CC) $(CFLAGS) $(SRC)/target.cpp

clean: 
	rm -r *.o $(BIN)/*

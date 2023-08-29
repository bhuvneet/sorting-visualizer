#This is a common makefile for sorting-visualizer project.
#Date: August 11, 2023
#By: Bhuvneet Thakur


CC = g++
CFLAGS = -std=c++11 -Wall
LDFLAGS = -lSDL2
SRC_DIR = ./SortingAlgo
HDR_DIR = ./SortingHeaders
OBJ_DIR = ./obj
OUTPUT_DIR = ./output
MAIN_FILE = $(SRC_DIR)/main.cpp

object_files = $(OBJ_DIR)/sort.o $(OBJ_DIR)/bubbleSort.o $(OBJ_DIR)/bucketSort.o $(OBJ_DIR)/heapSort.o $(OBJ_DIR)/insertionSort.o $(OBJ_DIR)/mergeSort.o $(OBJ_DIR)/quickSort.o $(OBJ_DIR)/selectionSort.o

.PHONY: all clean

all: $(OUTPUT_DIR)/sort_visualizer

$(OUTPUT_DIR)/sort_visualizer: $(object_files)
	mkdir -p $(OUTPUT_DIR)
	$(CC) $(CFLAGS) $^ $(MAIN_FILE) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HDR_DIR)/%.h
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<


clean:
	rm -rf $(OBJ_DIR) $(OUTPUT_DIR)
		


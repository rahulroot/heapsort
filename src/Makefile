# Makefile to build tree driver program
# --- macros
CC=g++
CFLAGS=  -Wall -g
MAX_OBJ= AMaxHeapSort.o
MIN_OBJ= AMinHeapSort.o
#
#
# # --- targets

max:   $(MAX_OBJ) 
	$(CC)  -o max  $(MAX_OBJ) 

AMaxHeapSort.o: AMaxHeapSort.cpp
	$(CC) $(CFLAGS) -c AMaxHeapSort.cpp

min:   $(MIN_OBJ) 
	$(CC)  -o min  $(MIN_OBJ) 

AMinHeapSort.o: AMinHeapSort.cpp
	$(CC) $(CFLAGS) -c AMinHeapSort.cpp

# --- remove binary and executable files
clean:
	rm -f max min $(MAX_OBJ) $(MIN_OBJ)

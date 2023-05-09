CC=g++
CFLAGS=-Wall -std=c++17
BINS=matriz
all: clean programa

programa:
	$(CC) $(CFLAGS) -o matriz matrizEnlazada.cpp

clean:
	@echo " [CLN] Eliminando archivos binarios!!"
	@rm -f $(BINS)

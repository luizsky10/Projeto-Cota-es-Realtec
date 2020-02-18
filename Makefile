all: produto.o main.o
	$(CCC) -O3 produto.o main.o -o cotacao.exe

main.o: main.cpp
	$(CCC) -O3 -c main.cpp -o main.o
	
Produto.o: Produto.cpp
	$(CCC) -O3 -c produto.cpp -o produto.o
	


clean: 
	rm -f pcv
	rm -f *.o

# ---------------------------------------------------------------------
# Compiler selection 
# ---------------------------------------------------------------------

CCC = g++
CC  = gcc

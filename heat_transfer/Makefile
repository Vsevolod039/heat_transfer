ht.out: main.o heat_transfer.o barrier.o
	g++ main.o heat_transfer.o barrier.o -o ht.out
main.o: main.cpp
	g++ -c main.cpp
heat_transfer.o: heat_transfer.cpp
	g++ -c heat_transfer.cpp
barrier.o: barrier.cpp
	g++ -c barrier.cpp

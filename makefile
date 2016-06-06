all: clean todx.out

todx.out: fabric.o main.o
	g++ -o todx.out main.o fabric.o

main.o: main.cpp
	g++ -c -Wall main.cpp

fabric.o: fabric.h fabric.cpp
	g++ -c -Wall fabric.cpp

run: todx.out
	./todx.out

clean:
	 rm -f *.o *.out *.h.gch

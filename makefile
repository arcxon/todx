all: todx.out

todx.out: fabric.o main.o
	g++ -o build/todx.out build/main.o build/fabric.o

main.o: build-dir main.cpp
	g++ -c -Wall main.cpp -o build/main.o

fabric.o: build-dir fabric.h fabric.cpp
	g++ -c -Wall fabric.cpp -o build/fabric.o

run: todx.out
	./build/todx.out

build-dir:
	mkdir -pv build

clean:
	rm -r build
	rm -f data.tdx

test: test.o AdjMatrix.o AdjList.o
	g++ test.o AdjMatrix.o AdjList.o -o test

test.o: test.cpp
	g++ -c test.cpp -std=c++11

AdjMatrix.o: AdjMatrix.h AdjMatrix.cpp
	g++ -c AdjMatrix.cpp -std=c++11

AdjList.o: AdjList.h AdjList.cpp
	g++ -c AdjList.cpp -std=c++11

clean:
	rm *.o
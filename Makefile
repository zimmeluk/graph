AdjMatrix.o: AdjMatrix.h
	g++ -c AdjMatrix.cpp -std=c++11

AdjList.o: AdjList.h
	g++ -c AdjList.cpp -std=c++11

clean:
	rm *.o
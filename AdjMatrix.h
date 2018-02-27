#ifndef _EDGE_
#define _EDGE_

struct Edge {
	int v, w;
	Edge(int v = -1, int w = -1) : v(v), w(w) { }
};

#endif

#ifndef _ADJMATRIX_H_
#define _ADJMATRIX_H_

#include <vector>

class AdjMatrix {
private:
	int num_V;
	int num_E;
	bool dir;
	std::vector <std::vector <bool> > adj;
public:
	AdjMatrix(int, bool);
	~AdjMatrix();
	int V() const;
	int E() const;
	bool directed() const;
	void insert(Edge);
	void remove(Edge);
	bool edge(int, int) const;
	void print();

	class it;
	friend class it;
};

#endif
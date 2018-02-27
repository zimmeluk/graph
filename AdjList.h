#ifndef _EDGE_
#define _EDGE_

struct Edge {
	int v, w;
	Edge(int v = -1, int w = -1) : v(v), w(w) { }
};

#endif

#ifndef _ADJLIST_H_
#define _ADJLIST_H_

#include <vector>

class AdjList {
private:
	int num_V;
	int num_E;
	bool dir;

	struct node {
		int v;
		node* next;
		node(int x, node* t) { v = x; next = t; }
	};

	typedef node* link;
	std::vector <link> adj;
public:
	AdjList(int, bool);
	~AdjList();
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
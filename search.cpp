#include <vector>

template <class Graph> class DFS {
	int cnt;
	const Graph &G;
	vector <int> ord;

	void searchC(int v) {
		ord[v] = cnt++;
		typename Graph::it it(G, v);
		for (int t = it.begin(); !it.end(); t = it.next()) {
			if (ord[t] == -1) searchC(t);
		}
	}

public:
	DFS(const Graph &G, int v = 0) : G(G), cnt(0), ord(G.V(), -1) {
		search(v);
	}

	int count() const { return cnt; }

	int operator[] (int v) const { return ord[v]; }
};
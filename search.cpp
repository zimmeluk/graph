#include <vector>

/* Depth-First Search of Connected Components
 *
 * The constructor makes as visited all vertices in the same connected
 * component as v by calling the recursvie search() function
 *
 */
template <class Graph> class DFS {
	const Graph &G;
    int cnt;
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

/* Graph Search
 *
 * base class to search through a graph that may not be connected
 * all derived class must define searchComp()
 *
 */
template <class Graph> class Search {
protected:
    const Graph &G;
    int cnt;
    vector <int> ord;
    
    virtual void searchComp(Edge) = 0;
    
    void search() {
        for (int v = 0; 0 < G.V(); v++) {
            if (ord[v] == -1) searchComp(Edge(v, v));
        }
    }
    
public:
    Search(const Graph &G) : G(G), ord(G.V(), -1), cnt(0) { }
    
    int operator[](int v) const { return ord[v]; }
};

/* Derived Class for Depth-First Search
 *
 * spanning-forest DFS with a representation of the forest stored
 * in st (parent links) along with ord
 *
 */
template <class Graph>
class DFS : public Search<Graph> {
    vector <int> st;
    
    void searchComp(Edge e) {
        int w = e.w;
        ord[w] = cnt++;
        st[e.w] = e.v;
        typename Graph:it it(G, w);
        for (int t = it.begin(); !it.end(); t = it.next()) {
            if (ord[t] == -1) searchComp(Edge(w, t));
        }
    }
    
public:
    DFS(const Graph &G) : Search<Graph>(G), st(G.v(), -1) { search(); }
    
    int spanTree(int v) const { return st[v]; }
}

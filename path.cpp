#include <vector>
#include <stack>

/* Vertex Degrees
 *
 * The degree of a vertex is the number of edges incident on it.
 *
 */
template <class Graph> class Degree {
    const Graph &G;
    std::vector <int> degree;
public:
    Degree(const Graph &G) : G(G), degree(G.V()), 0) {
        for (int v = 0; v < G.V(); v++) {
            typename Graph::it it(G, v);
            for (int w = it.begin(); !it.end(); w = it.next()) {
                degree[v]++;
            }
        }
    }
    
    int operator[] (int v) const { return degree[v]; }
};

/* Simple Path Search
 *
 * A simple path is a path in a graph which has distinct edges and vertices.
 *
 * Uses a recursive depth-first search to find a simple path connecting two
 * given vertices in a graph
 *
 */
template <class Graph> class SimplePath {
	const Graph &G;
	std::vector <bool> visited;
	bool found;

	bool searchR(int v, int w) {
		if (v == w) return true;
		visited[v] = true;
		typename Graph::it it(G, v);
		for (int t = it.begin(); !it.end(); t = it.next()) {
			if (!visited[t]) {
				if (searchR(t, w)) return true;
			}
		}
		return false;
	}

public:
	SimplePath(const Graph &G, int v, int w) : G(G), visited(G.V(), false) {
		found = searchR(v, w);
	}

	bool exists() const { return found; }
};

/* Hamilton Path
 *
 * Given two vertices, is there a simple path connecting them that visits
 * every vertex in the graph exactly once?
 *
 */
template <class Graph> class HamiltonPath {
	const Graph &G;
	std::vector <bool> visited;
	bool found;

	bool searchR(int v, int w, int d) {
		if (v == w) return (d == 0);
		visited[v] = true;
		typename Graph::it it(G, v);
		for (int t = it.begin(); !it.end(); t = it.next()) {
			if (!visited[t]) {
				if (searchR(t, w, d - 1)) return true;
			}
		}
		visited[v] = false;
		return false;
	}

public:
	HamiltonPath(const Graph &G, int v, int w) : G(G), visited(G.V(), false) {
		found = searchR(v, w);
	}

	bool exists() const { return found; }
};

/* Euler Path Existence
 *
 * Is there a path connecting two given vertices that uses each edge in the
 * graph exactly once?
 *
 */
template <class Graph> class EulerPath {
	Graph G;
	int v, w;
	bool found;
	std::stack <int> S;
	int tour(int v);
public:
	EulerPath(const Graph &G, int v, int w) : G(G), v(v), w(w) {
		Degree<Graph> deg(G);
		int t = deg[v] + deg[w];
		if ((t % 2) != 0) { found = false; return; }
		for (t = 0; t < G.V(); t++) {
			if ((t != v) && (t != w)) {
				if ((deg[t] % 2) != 0) {
					found = false; return;
				}
			}
		}
		found = true;
	}

	bool exists() const { return found; }

	int tour(int v) {
		while (true) {
			typename Graph::it it(G, v);
			int w = it.begin();
			if (it.end()) break;
			S.push(v);
			G.remove(Edge(v, w));
			v = w;
		}
		return v;
	}

	void show() {
		if (!found) return;
		while (tour(v) == v && !S.empty()) {
			v = S.pop();
			std::cout << "-" << v;
		}
		std::cout << std::endl;
	}
}

#include <stdio.h>
#include <iostream>
#include <vector>
#include "AdjMatrix.h"

using namespace std;

AdjMatrix::AdjMatrix(int V, bool digraph = false) : adj(V), num_V(V), num_E(0), dir(digraph) {
	for (int i = 0; i < V; i++) {
		adj[i].assign(V, 0); // assign all vertices a value of 0
	}
}

AdjMatrix::~AdjMatrix() { }

int AdjMatrix::V() const { return num_V; }

int AdjMatrix::E() const { return num_E; }

bool AdjMatrix::directed() const { return dir; }

void AdjMatrix::insert(Edge e) {
	int v = e.v, w = e.w;
	if (adj[v][w] == false) num_E++;
	adj[v][w] = true;
	if (!dir) adj[w][v] = true;
}

void AdjMatrix::remove(Edge e) {
	int v = e.v, w = e.w;
	if (adj[v][w] == true) num_E--;
	adj[v][w] = false;
	if (!dir) adj[w][v] = false;
}

bool AdjMatrix::edge(int v, int w) const {
	return adj[v][w];
}

void AdjMatrix::print() {
	cout << "\t|";
	int i = 0;
	for (auto it = adj.begin(); it != adj.end(); it++) {
		cout << "  " << i++;
	}
	cout << endl;
	cout << "----------" << endl;

	for (int i = 0; i < adj[0].size(); i++) {
		cout << "  " << i << "\t|";
		for (auto it = adj[i].begin(); it != adj[i].end(); it++) {
			cout << "  " << *it;
		}
		cout << endl;
	}
}

class AdjMatrix::it {
	const AdjMatrix &G;
	int i, v;
public:
	it(const AdjMatrix &G, int v) : G(G), v(v), i(-1) { }

	int begin() {
		i = -1;
		return next();
	}

	int next() {
		for (i++; i < G.V(); i++) {
			if (G.adj[v][i] == true) return i;
		}
		return -1;
	}

	bool end() { return i >= G.V(); }
};

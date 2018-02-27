#include <stdio.h>
#include <iostream>
#include <vector>
#include "AdjList.h"

using namespace std;

AdjList::AdjList(int V, bool dir = false) : adj(V), num_V(V), num_E(0), dir(dir) {
	adj.assign(V, 0);
}

AdjList::~AdjList() {
	for (auto it = adj.begin(); it != adj.end(); it++) {
		delete *it;
	}
}

int AdjList::V() const { return num_V; }

int AdjList::E() const { return num_E; }

bool AdjList::directed() const { return dir; }

void AdjList::insert(Edge e) {
	int v = e.v, w = e.w;
	adj[v] = new node(w, adj[v]);
	if (!dir) adj[w] = new node(v, adj[w]);
	num_E++;
}

void AdjList::remove(Edge e) {
	int v = e.v; int w = e.w;
	node* head = adj[w];
	node* del;
}

bool AdjList::edge(int v, int w) const {
	node* head = adj[v];
	while (head != NULL) {
		if (head->v == v) return true;
		head = head->next;
	}

	return false;
}

void AdjList::print() {
	printf("----------\n");
	for(int v = 0; v < num_V; v++) {
		printf(" %d: ", v);

		for(node *cur = adj[v]; cur != NULL; cur = cur->next) {
        	printf( " %d", cur->v );
    	}
    	printf("\n");  
	}
}

class AdjList::it {
	const AdjList &G
	int v;
	link t;
public:
	it(const AdjList &G, int v) : G(G), v(v) { t = 0; }

	int begin() {
		t = G.adj[v]
		return t ? t->v : -1;
	}

	int next() {
		if (t) t = t->next;
		return t ? t->v : -1;
	}

	int end() { return t == 0; }
};
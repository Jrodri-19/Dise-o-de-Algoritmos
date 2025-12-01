#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int u, v;
	int w;
	bool operator<(const Edge& other) const {
		return w < other.w; // comparar por peso
	}
};

// ------------------- DSU / UNION-FIND -------------------
struct DSU {
	vector<int> parent, rank;
	
	DSU(int n) {
		parent.resize(n);
		rank.resize(n, 0);
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}
	
	int find(int x) {
		if (parent[x] != x)
			parent[x] = find(parent[x]); // path compression
		return parent[x];
	}
	
	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return;
		
		if (rank[x] < rank[y]) swap(x, y);
		parent[y] = x;
		if (rank[x] == rank[y]) rank[x]++;
	}
};

// ------------------- KRUSKAL -------------------
int main() {
	int n, m;
	cin >> n >> m;  // n nodos, m aristas
	
	vector<Edge> edges(m);
	
	for (int i = 0; i < m; i++) {
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
		edges[i].u--; // si vienen 1-indexados
		edges[i].v--;
	}
	
	sort(edges.begin(), edges.end());  // ordenar por peso ascendente
	
	DSU dsu(n);
	int mst_weight = 0;
	vector<Edge> mst;
	
	for (auto &e : edges) {
		if (dsu.find(e.u) != dsu.find(e.v)) {
			dsu.unite(e.u, e.v);
			mst_weight += e.w;
			mst.push_back(e);
		}
	}
	
	cout << "Peso total del MST: " << mst_weight << "\n";
	cout << "Aristas del MST:\n";
	for (auto &e : mst) {
		cout << e.u+1 << " - " << e.v+1 << "  (peso " << e.w << ")\n";
	}
	
	return 0;
}

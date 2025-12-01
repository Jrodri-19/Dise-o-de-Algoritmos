#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int v;   // nodo destino
	int w;   // peso
};

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<vector<Edge>> adj(n);
	
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;  // 0-index
		
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	
	vector<bool> visited(n, false);
	vector<pair<int,int>> mstEdges;
	int mst_weight = 0;
	
	// (peso, nodo, padre)
	priority_queue<
		tuple<int,int,int>,
		vector<tuple<int,int,int>>,
		greater<tuple<int,int,int>>
		> pq;
	
	// iniciar en nodo 0
	pq.push(make_tuple(0, 0, -1));
	
	while (!pq.empty()) {
		tuple<int,int,int> top = pq.top();
		pq.pop();
		
		int w     = get<0>(top);
		int u     = get<1>(top);
		int parent = get<2>(top);
		
		if (visited[u]) continue;
		visited[u] = true;
		
		mst_weight += w;
		
		if (parent != -1) {
			mstEdges.push_back({parent, u});
		}
		
		for (auto &e : adj[u]) {
			if (!visited[e.v]) {
				pq.push(make_tuple(e.w, e.v, u));
			}
		}
	}
	
	cout << "Peso total del MST: " << mst_weight << "\n";
	cout << "Aristas del MST:\n";
	for (auto &e : mstEdges) {
		cout << e.first + 1 << " - " << e.second + 1 << "\n";
	}
	
	return 0;
}

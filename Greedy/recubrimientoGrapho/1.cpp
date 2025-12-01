#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> adj(n);
	vector<pair<int,int>> edges;
	
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--; // opcional: para usar 0-index
		edges.push_back({u, v});
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vector<bool> coveredEdge(m, false);
	vector<bool> used(n, false);
	
	vector<int> cover;  // resultado
	
	// Mientras existan aristas sin cubrir
	for (int i = 0; i < m; i++) {
		if (!coveredEdge[i]) {
			int u = edges[i].first;
			int v = edges[i].second;
			
			// Añadir ambos extremos al recubrimiento
			cover.push_back(u);
			cover.push_back(v);
			
			// Marcar las aristas incidentes a u o v como cubiertas
			for (int j = 0; j < m; j++) {
				if (!coveredEdge[j]) {
					int a = edges[j].first;
					int b = edges[j].second;
					if (a == u || a == v || b == u || b == v) {
						coveredEdge[j] = true;
					}
				}
			}
		}
	}
	
	// Eliminar duplicados si los hubiera
	sort(cover.begin(), cover.end());
	cover.erase(unique(cover.begin(), cover.end()), cover.end());
	
	// Mostrar resultado
	cout << "Recubrimiento (vertex cover):\n";
	for (int u : cover)
		cout << u + 1 << " "; // imprimir 1-indexado si quieres
	cout << "\n";
	
	return 0;
}

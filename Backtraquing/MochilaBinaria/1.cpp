#include <bits/stdc++.h>
using namespace std;

int n, C;
vector<int> peso, valor;

// Mejor solución encontrada
int mejorValor = 0;
vector<int> mejorConjunto;

// Conjunto actual (según las decisiones tomadas)
vector<int> actual;

// --------------------------------------------------------
// Backtracking binario
// i: índice del ítem que estamos decidiendo (0..n-1)
// pesoAct, valorAct: acumulados hasta ahora
// --------------------------------------------------------
void backtrackingBinario(int i, int pesoAct, int valorAct) {
	
	// Si ya decidimos sobre todos los ítems (hoja del árbol):
	if (i == n) {
		if (valorAct > mejorValor) {
			mejorValor = valorAct;
			mejorConjunto = actual;
		}
		return;
	}
	
	// =====================================================
	// 1) Opción izquierda: incluir item i
	// =====================================================
	if (pesoAct + peso[i] <= C) {
		actual.push_back(i);
		backtrackingBinario(i + 1, pesoAct + peso[i], valorAct + valor[i]);
		actual.pop_back();
	}
	
	// =====================================================
	// 2) Opción derecha: NO incluir item i
	// =====================================================
	backtrackingBinario(i + 1, pesoAct, valorAct);
}


int main() {
	cin >> n >> C;
	
	peso.resize(n);
	valor.resize(n);
	
	for (int i = 0; i < n; i++)
		cin >> peso[i] >> valor[i];
	
	backtrackingBinario(0, 0, 0);
	
	// Mostrar resultados
	cout << "Mejor valor: " << mejorValor << "\n";
	
	int pesoTotal = 0;
	cout << "Items seleccionados (1-based indices): ";
	for (int idx : mejorConjunto) {
		cout << (idx + 1) << " ";
		pesoTotal += peso[idx];
	}
	cout << "\nPeso total = " << pesoTotal << "\n";
	
	return 0;
}

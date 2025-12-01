#include <bits/stdc++.h>
using namespace std;

// Datos del problema
int n, C;                      // número de objetos y capacidad
vector<int> peso, valor;       // peso[i], valor[i]

// Mejor solución encontrada
int mejorValor = 0;
vector<int> mejorConjunto;

// Conjunto actual que se está explorando
vector<int> actual;

// ---------------------------------------------------------
// Backtracking combinatorio
// start: siguiente índice desde el cual puedo escoger
// pesoAct, valorAct: peso y valor acumulados hasta ahora
// ---------------------------------------------------------
void backtracking(int start, int pesoAct, int valorAct) {
	
	// Actualizamos la mejor solución si es mejor
	if (valorAct > mejorValor) {
		mejorValor = valorAct;
		mejorConjunto = actual;
	}
	
	// Intentar agregar elementos con índice mayor al último usado
	for (int i = start; i < n; i++) {
		
		int nuevoPeso = pesoAct + peso[i];
		
		// Solo avanzamos si no se excede la capacidad
		if (nuevoPeso <= C) {
			actual.push_back(i);                         // elegir objeto i
			backtracking(i + 1, nuevoPeso, valorAct + valor[i]);
			actual.pop_back();                           // deshacer elección
		}
		// Si se excede, simplemente no lo tomo (árbol combinatorio estándar)
	}
}

int main() {
	cin >> n >> C;
	
	peso.resize(n);
	valor.resize(n);
	
	for (int i = 0; i < n; i++)
		cin >> peso[i] >> valor[i];
	
	backtracking(0, 0, 0);
	
	// ---- Mostrar resultados ----
	cout << "Mejor valor obtenido: " << mejorValor << "\n";
	
	int pesoTotal = 0;
	cout << "Objetos tomados (indices 1-based): ";
	for (int i : mejorConjunto) {
		cout << (i + 1) << " ";
		pesoTotal += peso[i];
	}
	cout << "\nPeso total: " << pesoTotal << "\n";
	
	return 0;
}

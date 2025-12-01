#include <bits/stdc++.h>
using namespace std;

struct Tarea {
	int beneficio;
	int deadline;
};

// Comparar por beneficio en orden descendente
bool cmp(const Tarea &a, const Tarea &b) {
	return a.beneficio > b.beneficio;
}

int main() {
	int n;
	cin >> n;
	
	vector<Tarea> tareas(n);
	int maxDeadline = 0;
	
	for (int i = 0; i < n; i++) {
		cin >> tareas[i].beneficio >> tareas[i].deadline;
		maxDeadline = max(maxDeadline, tareas[i].deadline);
	}
	
	// Ordenar tareas por beneficio más alto primero
	sort(tareas.begin(), tareas.end(), cmp);
	
	// Slots del tiempo (1-indexados)
	vector<int> slot(maxDeadline + 1, -1);
	
	int beneficioTotal = 0;
	
	// Intentar asignar cada tarea en el último tiempo libre posible
	for (int i = 0; i < n; i++) {
		for (int t = tareas[i].deadline; t >= 1; t--) {
			if (slot[t] == -1) {      // ese tiempo está libre
				slot[t] = tareas[i].beneficio;
				beneficioTotal += tareas[i].beneficio;
				break;
			}
		}
	}
	
	// Mostrar resultado
	cout << "Beneficio total: " << beneficioTotal << "\n";
	cout << "Tareas realizadas (beneficios en cada tiempo):\n";
	
	for (int t = 1; t <= maxDeadline; t++) {
		if (slot[t] != -1)
			cout << "Tiempo " << t << ": B=" << slot[t] << "\n";
		else
			cout << "Tiempo " << t << ": libre\n";
	}
	
	return 0;
}

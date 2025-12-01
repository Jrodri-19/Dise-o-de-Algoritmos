#include <iostream>
#include <vector>
#include <algorithm> // Necesaria para la función sort()

using namespace std;

// Función principal que resuelve el problema
void resolver_problema_ordenamiento_parcial(vector<int>& A, int L, int U) {
	
	// 1. Extraer los valores que están dentro del rango [L, U]
	vector<int> valores_en_rango;
	for (int x : A) {
		if (x >= L && x <= U) {
			valores_en_rango.push_back(x);
		}
	}
	
	// 2. Ordenar esos valores extraídos
	// Ejemplo: [7, 5, 4, 8] -> [4, 5, 7, 8]
	sort(valores_en_rango.begin(), valores_en_rango.end());
	
	// 3. Volver a colocar los valores ordenados en sus posiciones originales
	int indice_temp = 0; // Puntero para el vector ya ordenado
	
	// Recorremos el arreglo original (A) y modificamos in-place (usando la referencia '&')
	for (int& x : A) {
		// La condición debe ser la misma que usamos para extraer: 
		// ¿Este elemento 'x' (en su posición original) estaba en el rango [L, U]?
		if (x >= L && x <= U) {
			// Reemplazamos el valor original con el siguiente valor de la lista ordenada
			x = valores_en_rango[indice_temp];
			indice_temp++;
		}
	}
}

int main() {
	// Datos de entrada del ejemplo:
	vector<int> A = {3, 7, 2, 5, 9, 4, 8, 1};
	int L = 4;
	int U = 8;
	
	cout << "Arreglo Inicial: [3, 7, 2, 5, 9, 4, 8, 1]" << endl;
	cout << "Rango a ordenar: [" << L << ", " << U << "]" << endl;
	
	resolver_problema_ordenamiento_parcial(A, L, U);
	
	// Mostrar el resultado final (La salida correcta)
	cout << "Arreglo Resultante: [";
	for (size_t i = 0; i < A.size(); ++i) {
		cout << A[i] << (i == A.size() - 1 ? "" : ", ");
	}
	cout << "]" << endl;
	
	// La salida correcta es: [3, 4, 2, 5, 9, 7, 8, 1]
	
	return 0;
}

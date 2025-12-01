#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int L;
	cin >> L;
	int n;
	cin >> n;
	
	vector<int> c(n + 2);
	c[0] = 0;
	c[n + 1] = L;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	
	vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
	vector<vector<int>> cut(n + 2, vector<int>(n + 2, -1));
	
	// DP de intervalos
	for (int len = 2; len < n + 2; len++) {
		for (int i = 0; i + len < n + 2; i++) {
			int j = i + len;
			dp[i][j] = INT_MAX;
			
			for (int k = i + 1; k < j; k++) {
				int cost = dp[i][k] + dp[k][j] + (c[j] - c[i]);
				if (cost < dp[i][j]) {
					dp[i][j] = cost;
					cut[i][j] = k; // guardamos el corte óptimo
				}
			}
			
			if (dp[i][j] == INT_MAX)
				dp[i][j] = 0;
		}
	}
	
	cout << "The minimum cutting is " << dp[0][n + 1] << ".\n";
	
	// Función para imprimir los cortes en orden
	function<void(int,int)> printCuts = [&](int i, int j) {
		if (cut[i][j] == -1) return;
		int k = cut[i][j];
		cout << c[k] << " ";      // imprimimos el corte
		printCuts(i, k);           // cortes a la izquierda
		printCuts(k, j);           // cortes a la derecha
	};
	
	cout << "Cuts at positions: ";
	printCuts(0, n + 1);
	cout << "\n";
	
	return 0;
}

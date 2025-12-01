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
	
	// DP de intervalos
	vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
	
	// len = tamaño del intervalo
	for (int len = 2; len < n + 2; len++) {
		for (int i = 0; i + len < n + 2; i++) {
			int j = i + len;
			
			dp[i][j] = INT_MAX;
			
			for (int k = i + 1; k < j; k++) {
				dp[i][j] = min(dp[i][j],
					dp[i][k] + dp[k][j] + (c[j] - c[i]));
			}
			
			if (dp[i][j] == INT_MAX)
				dp[i][j] = 0;
		}
	}
	
	cout << "The minimum cutting is " << dp[0][n + 1] << ".\n";
	
	return 0;
}

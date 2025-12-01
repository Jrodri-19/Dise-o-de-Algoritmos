#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main() {
	int n,c;
	cin>>n>>c;
	vi peso(n),valor(n);
	for(int i=0;i<n;i++)
		cin>>peso[i]>>valor[i];
	
	vector<vi>dp(n+1 ,vi(c+1,0));
	
	for(int i=1;i<=n;i++){
		for(int w=0;w<=c;w++){
			dp[i][w]=dp[i-1][w];
			if(w>=peso[i-1]){
				dp[i][w] = max(dp[i][w],
					valor[i-1]+dp[i-1][w-peso[i-1]]);
			}
		}
	}
	
	vi tomados;
	int w=c;
	for (int i = n; i > 0; i--) {
		if (dp[i][w] != dp[i-1][w]) {
			tomados.push_back(i);
			w -= peso[i-1];
		}
	}
	
	reverse(tomados.begin(), tomados.end());
	
	cout << "Objetos tomados (1-based): ";
	for (int x : tomados) cout << x << " ";
	cout << "\n";
	
	cout<<dp[n][c];
	return 0;
}

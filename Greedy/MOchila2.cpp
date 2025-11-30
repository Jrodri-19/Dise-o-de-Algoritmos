#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, W;
	cin >> n >> W;
	
	vector<double> value(n), weight(n);
	for (int i = 0; i < n; i++) cin >> value[i];
	for (int i = 0; i < n; i++) cin >> weight[i];
	
	// (densidad, valor, peso)
	vector<tuple<double,double,double>> items;
	
	for (int i = 0; i < n; i++) {
		double d = value[i] / weight[i];  // densidad
		items.push_back({d, value[i], weight[i]});
	}
	
	// ordenar por densidad de mayor a menor
	sort(items.begin(), items.end(),
		 [](auto &a, auto &b){
			 return get<0>(a) > get<0>(b);
		 });
	
	double total = 0.0;
	double remaining = W;
	
	for (auto &it : items) {
		double d = get<0>(it);
		double val = get<1>(it);
		double wt = get<2>(it);
		
		if (remaining == 0) break;
		
		if (wt <= remaining) {
			// tomar entero
			total += val;
			remaining -= wt;
		} else {
			// tomar fracción
			double frac = remaining / wt;
			total += val * frac;
			remaining = 0;
		}
	}
	
	cout << fixed << setprecision(10) << total << "\n";
}

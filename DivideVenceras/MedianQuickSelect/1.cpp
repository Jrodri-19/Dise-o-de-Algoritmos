#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int quickSelect(vi v, int k){ // k-esimo mayor
	if(v.size() == 1) return v[0];
	
	int p = v[v.size()/2];
	vi may, men, eq;
	
	for(int x : v){
		if(x > p) may.push_back(x);
		else if(x < p) men.push_back(x);
		else eq.push_back(x);
	}
	
	if(k <= (int)may.size())
		return quickSelect(may, k);
	
	if(k <= (int)may.size() + (int)eq.size())
		return p;
	
	return quickSelect(men, k - may.size() - eq.size());
}
	
// Calcula la mediana usando quickselect
double mediana(vi v){
	int n = v.size();
	
	if(n % 2 == 1){
		
		return quickSelect(v, n/2 + 1);
	} else {
		
		int m1 = quickSelect(v, n/2);     // n/2-esimo mayor
		int m2 = quickSelect(v, n/2 + 1); // (n/2 + 1)-esimo mayor
		return (m1 + m2) / 2.0;
	}
}
	
int main(){
	vi v = {7, 3, 5, 9, 5, 1, 5, 8, 2};
	cout << "Mediana = " << mediana(v);
	return 0;
}
		

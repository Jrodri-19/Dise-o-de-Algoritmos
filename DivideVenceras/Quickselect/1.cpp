/*
Diseñe un algoritmo basado en la técnica de divide y vencerás 
que permita calcular el k-ésimo mayor elemento de un vector no ordenado, 
sin ordenarlo completamente. Vector: [7, 3, 5, 9, 5, 1, 5, 8, 2]

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;


int quickSelect(vi v, int k){
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
	
void solve(){
	vi v = {7, 3, 5, 9, 5, 1, 5, 8, 2};
	int k;cin>>k;
	cout<<quickSelect(v,k);
}

int main() {
	solve();
	return 0;
}

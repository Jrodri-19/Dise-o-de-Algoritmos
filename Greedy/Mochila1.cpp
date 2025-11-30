#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<char> vc;


void solve(){
	int n,w;cin>>n>>w;
	vi b(n),p(n);
	for(auto& t: b)cin>>t;
	for(auto& t: p)cin>>t;
	
	vector<int> idx(n);
	iota(idx.begin(), idx.end(), 0);
	
	sort(idx.begin(),
		 idx.end(),
		 [&](int i,int j)
	{
		long double left =(long double) b[i] * (long double) p[j];
		long double right = (long double) b[j] * (long double) p[i];
		if (left == right) return i < j;
		return left > right;
	});
	long double remaining = w;
	long double total = 0.0L;
	
	for (int id : idx) {
		if (remaining <= 0.0L) break;
		int weight = p[id];
		int value = b[id];
		
		if (weight == 0) {
			// Si el peso es 0, podemos tomar el objeto completo sin consumir capacidad
			// (valor finito por cada objeto). Solo sumamos su valor.
			total += (long double) value;
			continue;
		}
		
		if ((long double) weight <= remaining) {
			// tomar entero
			total += (long double) value;
			remaining -= (long double) weight;
		} else {
			// tomar fracción necesaria
			long double frac = remaining / (long double) weight;
			total += (long double) value * frac;
			remaining = 0.0L;
			break;
		}
		
	
	}
	cout.setf(std::ios::fixed); 
	cout << setprecision(10) << (double) total << '\n';
}




int main() 
{
	solve();
	return 0;
}


#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int maxCantidad(vi p, int k){
	sort(p.rbegin(),p.rend());
	int pa=0;
	for(auto t:p){
		if(pa+t<=k){
			pa += t;
		}
	}
	return pa;
}
void solve(){
	int n,k;cin>>n>>k;
	vi v(n);
	for(auto & t: v)cin>>t;
	cout<<maxCantidad(v,k);
}
int main() {
	solve();
	return 0;
}


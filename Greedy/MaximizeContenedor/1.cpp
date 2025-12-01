#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int maxCantidad(vi p, int k){
	sort(p.begin(),p.end());
	int pa=0,c=0;
	for(auto t:p){
		if(pa+t<=k){
			pa += t;
			c++;
		}else break;
	}
	return c;
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


#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int indiceIgualValor(const vi &X, int l, int r){
	if(l > r) return -1;
	
	int mid = (l + r) / 2;
	
	if(X[mid] == mid) 
		return mid;
	
	if(X[mid] > mid)
		return indiceIgualValor(X, l, mid - 1);
	else
		return indiceIgualValor(X, mid + 1, r);
}
	
int main(){
	vi X = {-3, -1, 0, 3, 5, 7};
	
	int idx = indiceIgualValor(X, 0, X.size() - 1);
	
	if(idx != -1)
		cout << "Existe i = " << idx << " tal que X[i] = " << X[idx];
	else
		cout << "No existe";
	
	return 0;
}
	

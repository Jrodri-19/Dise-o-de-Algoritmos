#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
bool existeIgualIndice(const vector<int> &X, int l, int r){
	if(l > r) return false;
	
	int mid = (l + r) / 2;
	
	if(X[mid] == mid) return true;
	
	if(X[mid] > mid)
		return existeIgualIndice(X, l, mid - 1);
	else
		return existeIgualIndice(X, mid + 1, r);
}
	
int main(){
	vector<int> X = {-3, -1, 0, 3, 5, 7};
	
	if(existeIgualIndice(X, 0, X.size() - 1))
		cout << "Existe i tal que X[i] = i";
	else
		cout << "No existe";
	
	return 0;
}
		

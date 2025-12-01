#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

void mergeArrays(vi &v, int l, int m, int r){
	vi L(v.begin() + l, v.begin() + m + 1);
	vi R(v.begin() + m + 1, v.begin() + r + 1);
	
	int i = 0, j = 0, k = l;
	
	while(i < (int)L.size() && j < (int)R.size()){
		if(L[i] <= R[j]) v[k++] = L[i++];
		else             v[k++] = R[j++];
	}
	
	while(i < (int)L.size()) v[k++] = L[i++];
	while(j < (int)R.size()) v[k++] = R[j++];
}

void mergeSort(vi &v, int l, int r){
	if(l >= r) return;
	
	int m = (l + r) / 2;
	
	mergeSort(v, l, m);
	mergeSort(v, m + 1, r);
	
	mergeArrays(v, l, m, r);
}

// Eliminar duplicados de un vector ORDENADO
vi eliminarDuplicados( vi &v){
	mergeSort(v, 0, v.size() - 1);
	vi res;
	for(int x : v){
		if(res.empty() || res.back() != x)
			res.push_back(x);
	}
	return res;
}

int main(){
	vi v = {7, 3, 5, 9, 5, 1, 5, 8, 2};
	
	v = eliminarDuplicados(v);
	
	cout << "Vector ordenado: ";
	for(int x : v) cout << x << " ";
	
	return 0;
}
	

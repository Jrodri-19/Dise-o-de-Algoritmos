#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

void quickSort(vi &v){
	if(v.size() <= 1) return;
	
	int p = v[v.size()/2];
	vi men, eq, may;
	
	for(int x : v){
		if(x < p) men.push_back(x);
		else if(x > p) may.push_back(x);
		else eq.push_back(x);
	}
	
	quickSort(men);
	quickSort(may);
	
	int i = 0;
	for(int x : men) v[i++] = x;
	for(int x : eq)  v[i++] = x;
	for(int x : may) v[i++] = x;
}
	
int main(){
	vi v = {7, 3, 5, 9, 5, 1, 5, 8, 2};
	
	quickSort(v);
	
	cout << "Vector ordenado: ";
	for(int x : v) cout << x << " ";
	
	return 0;
}
		

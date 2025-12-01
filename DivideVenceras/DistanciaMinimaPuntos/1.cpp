#include <bits/stdc++.h>
using namespace std;

struct Punto {
	double x, y;
};

double dist(Punto a, Punto b){
	return hypot(a.x - b.x, a.y - b.y);
}
	
double fuerzaBruta(vector<Punto> &P, int l, int r){
	double d = 1e18;
	for(int i = l; i <= r; i++)
		for(int j = i + 1; j <= r; j++)
		d = min(d, dist(P[i], P[j]));
	return d;
}
	
double franja(vector<Punto> &S, double d){
	double minD = d;
	
	for(int i = 0; i < S.size(); i++){
		for(int j = i + 1; j < S.size() && (S[j].y - S[i].y) < minD; j++){
			minD = min(minD, dist(S[i], S[j]));
		}
	}
	return minD;
}
	
double closest(vector<Punto> &Px){
	int n = Px.size();
	if(n <= 3)
		return fuerzaBruta(Px, 0, n - 1);
	
	int mid = n / 2;
	Punto midPoint = Px[mid];
	
	vector<Punto> L(Px.begin(), Px.begin() + mid);
	vector<Punto> R(Px.begin() + mid, Px.end());
	
	double dl = closest(L);
	double dr = closest(R);
	double d = min(dl, dr);
	
	vector<Punto> S;
	for(auto &p : Px)
		if(abs(p.x - midPoint.x) < d)
		S.push_back(p);
	
	sort(S.begin(), S.end(), [](Punto a, Punto b){
		return a.y < b.y;
	});
	
	return min(d, franja(S, d));
}

int main(){
	vector<Punto> P = {{2,3},{12,30},{40,50},{5,1},{12,10},{3,4}};
	
	sort(P.begin(), P.end(), [](Punto a, Punto b){
		return a.x < b.x;
	});
	
	cout << "Distancia mínima: " << closest(P);
	return 0;
}
	

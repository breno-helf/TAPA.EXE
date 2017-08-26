#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;
const int maxn = 1e2 + 10;

int n, m, a[maxn];

void solve(int x) {
	vector <pii> P;
	
	for(int i = 1; i <= n; ++i) {
		P.push_back( {a[i], i} );
	}
	
	sort(P.begin(), P.end());
	
	for(auto i: P) {
		if(!x) {
			return;
		}
		
		int id = i.second;
		
		++a[id];
		--x;
	}
}

int get() {
	int menor = INT_MAX;
	
	for(int i = 1; i <= n; ++i) {
		menor = min(menor, a[i]);
	}
 	
	int cont = 0;
	for(int i = 1; i <= n; ++i) {
		if(a[i] == menor + 1) {
			++cont;
		}
	}		
	
	return cont;
}

int main () {
	scanf("%d %d", &n, &m);
	
	for(int i = 1; i <= m; ++i) {
		int cost;
		scanf("%d", &cost);
		solve(cost % n);
	}
	
	printf("%d\n", get());
	
	return 0;
}


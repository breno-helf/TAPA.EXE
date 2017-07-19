#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i = a; i <= b; ++i)

const int maxn = 1e5 + 10;

int t, n;
int w[2][maxn];
int h[2][maxn];

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int hmin = INT_MAX;
		int wmin = INT_MAX;
		int hmax = INT_MIN;
		int wmax = INT_MIN;
		FOR(i,1,n){
			scanf("%d%d%d%d",&w[0][i],&w[1][i],&h[0][i],&h[1][i]);
			hmin = min(hmin,h[0][i]);
			hmax = max(hmax,h[1][i]);
			wmin = min(wmin,w[0][i]);
			wmax = max(wmax,w[1][i]);
		}
		bool ok = 0;
		FOR(i,1,n)
			if(h[0][i] <= hmin && hmax <= h[1][i] && w[0][i] <= wmin && wmax <= w[1][i])
				ok = true;
		if(ok) printf("ANO\n");
		else printf("NIE\n");
	}
	return 0;
}
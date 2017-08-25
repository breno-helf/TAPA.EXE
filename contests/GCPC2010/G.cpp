#include "bits/stdc++.h"
using namespace std;

#define debug(args...) fprintf(stderr, args)

const int MAXN = 15;
const int INF = -0x3f3f3f3f;

int t;
int g[MAXN][MAXN];

int dp[MAXN][1 << MAXN];

int f(int i, int mask) {
	if(dp[i][mask] == -1) {
		if(i >= 11) 
			return dp[i][mask] = 0;
		
		dp[i][mask] = INF;
		
		for(int k = 0; k < 11; ++k) {
			if((1 << k) & mask) 
				continue;
				
			if(!g[i][k])
				continue;
				
			if(f(i + 1, mask + (1 << k)) == INF)
				continue;
				
			dp[i][mask] = max(dp[i][mask], f(i + 1, mask + (1 << k)) + g[i][k]);
		}
	}

	return dp[i][mask];
}

int main() {
	scanf("%d", &t);
	
	while(t--) {
		for(int i = 0; i < 11; ++i) 
			for(int j = 0; j < 11; ++j)
				scanf("%d", &g[i][j]);
		
		memset(dp, -1, sizeof(dp));		
		
		printf("%d\n", f(0, 0));
	}
	
	return 0;
}

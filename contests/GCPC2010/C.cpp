#include "bits/stdc++.h"
using namespace std;

const int maxn = 1e5 + 10;

int t;

int n;
long long l[2], s[2];

long long d[2][maxn], pass[2][maxn];
long long dp[2][maxn];

long long f(int k, int i) {
	if(dp[k][i] == -1) {
		if(i == n) 
			return dp[k][i] = s[k];
			
		dp[k][i] = min(f(k, i + 1) + d[k][i], f(k ^ 1, i + 1) + pass[k][i]);
	}
	
	return dp[k][i];
}

int main() {
	scanf("%d", &t);
	
	while(t--) {
		scanf("%d %lld %lld %lld %lld", &n, &l[0], &l[1], &s[0], &s[1]);
		
		for(int k = 0; k <= 1; ++k) {
			for(int i = 1; i <= n - 1; ++i)
				scanf("%lld", &pass[k][i]);
			
			for(int i = 1; i <= n - 1; ++i)
				scanf("%lld", &d[k][i]);
		}
		
		memset(dp, -1, sizeof(dp));
		
		printf("%lld\n", min(l[0] + f(0, 1), l[1] + f(1, 1)));
	}
	
	return 0;
}

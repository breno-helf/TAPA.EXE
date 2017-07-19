#include "bits/stdc++.h"
using namespace std;

#define gc getchar_unlocked
#define pb push_back
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
typedef long long ll;
const int maxn = 20;

int n, m;
vector<int>adj[maxn];
ll dp[maxn][1<<maxn];

void read(int &x){
  char k = gc();
  x = 0;
	for(;k<'0'&&k>'9';k = gc()); 
	for(;'0'<=k&&k<='9';k = gc()) x = x*10+k-'0';
}

int main(){
	read(n);
	read(m);
	for(int i = 0; i < m; ++i){
		int u, v;
		read(u);
		read(v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int MASK = (1<<n)-1;
	FOR(v,0,n-1) dp[v][0] = 1;
	FOR(mask,1,(1<<n)-1)
		FOR(v,0,n-1){
			if((1<<v)&mask) continue;
			dp[v][mask] = 1;
			for(auto u: adj[v])
				if((1<<u)&mask)
					dp[v][mask] += dp[u][mask-(1<<u)];
		}
	ll ans = 0;
	FOR(v,0,n-1) ans += dp[v][MASK-(1<<v)];
	printf("%lld\n",ans-n);
	return 0;
}
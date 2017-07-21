#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define debug(args...) //fprintf(stderr,args)
const int maxn = 5e4 + 10;

int n, q;
int c[maxn];
vector<int>adj[maxn];

int dp[2][maxn], h[maxn];
int ini[maxn], fim[maxn], t;

void dfs(int v, int par){
	ini[v] = ++t;
	dp[1][v] = c[v];
	debug("%d\n",v);
	for(auto u: adj[v])
		if(u != par){
			h[u] = h[v] + 1;
			dfs(u,v);
			dp[1][v] ^= dp[0][u];
			dp[0][v] ^= dp[1][u];
		}
	fim[v] = t;
}

int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;

	FOR(i,1,n) cin >> c[i];

	FOR(i,1,n-1){
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	debug("read()\n");

	h[1] = 1;
	dfs(1,-1);

	debug("dfs ok\n");

	cin >> q;
	while(q--){
		int u, v;
		cin >> u >> v;

		if(ini[u] <= ini[v] && fim[v] <= fim[u]) cout << "INVALID\n";
		else{
			int nim = dp[0][1];
			
			if(h[u]%2) nim ^= dp[0][u];
			else nim ^= dp[1][u];

			if(h[v]%2) nim ^= dp[1][u];
			else nim ^= dp[0][u];

			if(!nim) cout << "NO\n";
			else cout << "YES\n";
		}
	}

	return 0;
}
#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define debug(args...) fprintf(stderr,args)
const int maxn = 1e5 + 10;

int t, n, m;
vector<int>adj[maxn];
bool mrk[maxn];
double soma;

void dfs(int v, int par, double cur){
	soma += cur/(cur+1);
	for(auto u: adj[v])
		if(u != par)
			dfs(u,v,cur+mrk[v]);
}

int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		FOR(i,1,n) adj[i].clear(), mrk[i] = false;
		FOR(i,1,n-1){
			int a, b;
			cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		cin >> m;
		FOR(i,1,m){
			int node;
			cin >> node;
			mrk[node] = true;
		}
		soma = 0;
		dfs(1,-1,0);
		cout << fixed << setprecision(10) << soma << '\n';
	}
	return 0;
}
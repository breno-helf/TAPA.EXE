#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define debug(args...) fprintf(stderr,args)
typedef pair<int,int>pii;
	
const int maxn = 2e5 + 10;

int n, m;

int h[maxn], low[maxn], t;
int mrk[maxn];

vector<pii>adj[maxn],rev[maxn],e;

set<int>ans;

void dfs(int v, int par){
	h[v] = low[v] = ++t;
	mrk[v] = 1;

	for(auto i: adj[v]){

		int u = i.first;
		int edge = i.second;

		if(edge == par) continue;

		if(!mrk[u]){
		
			dfs(u,edge);
			
			low[v] = min(low[v],low[u]);
			
			if(low[u] > h[v]){
				debug("bride(%d,%d)\n",v,u);
				for(auto j: rev[u]){
					int node = j.first;
					int id = j.second;
					if(node == v) continue;
					ans.erase(id);
				}
			}

		}
		else if(mrk[u] == 1) low[v] = min(low[v],h[u]);
	}
	mrk[v] = 2;
}

int main(){
	while(cin >> n >> m){
		
		FOR(i,1,n){
			adj[i].clear(); 
			rev[i].clear(); 
			mrk[i] = 0;
		}

		e.clear();

		ans.clear();

		FOR(i,1,m){
			int a, b;
			cin >> a >> b;

			e.pb(pii(a,b));

			if(b != 1) ans.insert(i);

			adj[a].pb(pii(b,i));
			rev[b].pb(pii(a,i));
		}

		t = 0;
		dfs(1,-1);

		for(int i = 0; i < e.size(); ++i){
			int id = i + 1;
			int u = e[i].first;
			int v = e[i].second;
			if(ans.find(id) != ans.end()){
				if(!mrk[u] || !mrk[v])
					ans.erase(id);
			}
		}

		cout << ans.size() << '\n';
		for(auto i: ans) cout << i << " ";
		cout << '\n';

	}
	return 0;
}
#include "bits/stdc++.h"
using namespace std;

#define debug(args...) //fprintf(stderr, args)
const int MAXN = 1e5 + 10;

int t, n, m;
vector <int> adj[MAXN];

vector <int> ans;

int low[MAXN], h[MAXN], id;
bool mrk[MAXN], on[MAXN];

int c[MAXN], cur;
vector <int> stk;

void dfs(int v) {
	low[v] = h[v] = ++id;
	mrk[v] = on[v] = true;
	stk.push_back(v);
	
	for(int i = 0; i < adj[v].size(); ++i) {
		int u = adj[v][i];
		
		if(!mrk[u]) {
			dfs(u);
			low[v] = min(low[v], low[u]);
		}
		else
			if(on[u])
				low[v] = min(low[v], h[u]);
	}
	
	if(low[v] == h[v]) {
		++cur;
		
		while(stk.back() != v) {
			int u = stk.back();
			on[u] = false;
			c[u] = cur;
			stk.pop_back();
		}
		
		stk.pop_back();
		c[v] = cur;
		on[v] = false;
	}
}

int deg[MAXN];
vector <int> dag[MAXN];

void dfs0(int v) {
	mrk[v] = true;
	
	for(int i = 0; i < dag[v].size(); ++i) {
		int u = dag[v][i];
		
		if(!mrk[u])
			dfs0(u);
	}
}

void solve() {
	ans.clear();
	
	id = 0;
	for(int i = 0; i < n; ++i) {
		mrk[i] = false;
		deg[i] = 0;
	}
		
	cur = 0;
	for(int i = 0; i < n; ++i)
		if(!mrk[i]) 
			dfs(i);
			
	debug("cur = %d\n", cur);
			
	debug("dfs end()\n");
	
	for(int i = 1; i <= cur; ++i)
		dag[i].clear();
		
	for(int i = 0; i < n; ++i)
		debug("%d -> %d\n", i, c[i]);
			
	for(int v = 0; v < n; ++v) 
		for(int i = 0; i < adj[v].size(); ++i) {
			int u = adj[v][i];
			
			int a = c[v];
			int b = c[u];
			
			if(a == b)
				continue;
				
			debug("(%d, %d)\n", a, b);
			
			dag[a].push_back(b);
			
			++deg[b];
		}
	
	set <int> ok;
	for(int i = 1; i <= cur; ++i)
		if(!deg[i])
			ok.insert(i);
			
	if(ok.size() > 1)
		return;
		
	memset(mrk, false, sizeof(mrk));
	
	int root = *ok.begin();
	
	dfs0(root);
	
	for(int i = 1; i <= cur; ++i)
		if(!mrk[i])
			return;
			
	for(int i = 0; i < n; ++i)
		if(ok.find(c[i]) != ok.end())
			ans.push_back(i); 
}

int main() {
	scanf("%d", &t);
	
	while(t--) {
		scanf("%d %d", &n, &m);
		
		for(int i = 0; i < n; ++i)
			adj[i].clear();
			
		for(int i = 1; i <= m; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			
			adj[u].push_back(v);
		}
		
		solve();
		
		if(ans.empty()) 
			printf("Confused\n\n");
		else {
			for(int i = 0; i < ans.size(); ++i) 
				printf("%d\n", ans[i]);
			
			printf("\n");
		}
	}
	
	return 0;
}

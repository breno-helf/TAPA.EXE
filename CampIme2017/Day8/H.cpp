#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define debug(args...) //fprintf(stderr, args)

typedef pair<int, int> pii;

const int MAX = 5e5 + 10;
const int POW = 30;

int n, q;
vector<int>adj[MAX];
int h[MAX],p[MAX];
int dp[POW][MAX];
int ini[MAX],fim[MAX],t;

void dfs(int u){
    ini[u] = ++t;
    for (int v : adj[u]){
	if (v != p[u]){
	    h[v] = h[u]+1;
	    p[v] = u;
	    dfs(v);
	}
    }
    fim[u] = ++t;
}

void precomp(){
    for (int i = 1; i <= n; i++)
	dp[0][i] = p[i];
  
    for (int k = 1; k < POW; k++)
	for (int i = 1; i <= n; i++)
	    dp[k][i] = dp[k - 1][dp[k - 1][i]];   
}

int lca(int x, int y) {
    if (h[x] > h[y]) swap(x, y);

    int d = h[y] - h[x];
    for (int k = POW - 1; k >= 0; k--) 
	if ((1 << k) & d)
	    y = dp[k][y];

    if(x == y) return x;

    for (int k = POW - 1; k >= 0; k--) {
	if (dp[k][x] != dp[k][y]) {
	    x = dp[k][x];
	    y = dp[k][y];
	}
    }

    return dp[0][x];
}

int ans;
int deg[MAX];

void add(int v, int u){
    if(u == v) return;
    debug("Adding (%d, %d)\n", u, v);
    ++deg[u];
    ++deg[v];
}

void build (vector<int>& vec) {
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    vector<pii> w;
    for (int v : vec) {
	debug ("--> %d %d %d\n", ini[v], fim[v], v);
	w.pb(pii(ini[v], v));
	w.pb(pii(fim[v], -v));
    }
    sort(w.begin(), w.end());
    stack<int> st;
    for (int i = 0; i < (int)w.size(); i++) {
	int v = w[i].second;
	if (v < 0) st.pop();
	else {
	    if (!st.empty()) {
		add(v, st.top());	
	    }	    
	    st.push(v);
	}
    }
}

int solve(vector<int>& vec) {
    if ((int)vec.size() == 1) return 0;
    if ((int)vec.size() == 2) return 1;

    vector<pii>w;
    vector<int>nodes;
    
    for (int v : vec){
	w.pb(pii(ini[v], v));
	nodes.pb(v);
    }

    sort(w.begin(), w.end());
    
    int c = lca(w[0].second, w[1].second);
    nodes.pb(c);	

    for(int i = 2; i < (int)w.size(); ++i){
	int last = c;
	c = lca(w[i-1].second,w[i].second);
	if (c != last) nodes.pb(c);
    }

    build(nodes);
    
    ans = 0;
    
    for (int v: nodes){
        if(deg[v] == 1) ++ans;
        deg[v] = 0;
    }

    return (ans+1)/2;
}


int main() {
    scanf("%d", &n);

    for (int i = 1; i < n; i++){
	int u, v;
	scanf("%d%d", &u,&v);
	
        adj[u].pb(v);
	adj[v].pb(u);
    }
    
    p[1] = 1;
    dfs(1);
    
    precomp();
    
    scanf("%d", &q);
    
    while(q--) {
	int m;
        vector<int> sub;

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
	    int u;
	    scanf("%d", &u);
	    sub.pb(u);
	}
	
	printf ("%d\n", solve(sub));
    }

    return 0;
}

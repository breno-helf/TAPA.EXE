#include "bits/stdc++.h"
using namespace std;

#define debug(args...) fprintf(stderr, args)

const int maxn = 1e4 + 10;

int n;
vector <int> adj[maxn];
typedef long long ll;

const ll hashA = 400009;
const ll hashB = 600011;
const ll MOD = 1e9 + 7;

ll val[maxn];
map <vector <int>, int> M;

int diameter;
int node;

int go[maxn];
int deg[maxn];
vector <int> vec[maxn];

void dfs(int v, int par, int d) {
    if(d > diameter) {
	diameter = d;
	node = v;
    }

    go[v] = par;

    for(auto u: adj[v])
	if(u != par) {
	    ++deg[v];
	    dfs(u, v, d + 1);
	}
}

void reorder(int v, int par = -1) {
    deg[v] = 0;

    for(auto u: adj[v])
	if(u != par) {
	    ++deg[v];
	    go[u] = v;
	    reorder(u, v);
	}
} 

void dfs0(int u, int p) {
    ll sum = 0;
    for (auto v : adj[u]) {
          if (v != p) {
                dfs0(v, u);
                sum += val[v];
		sum %= MOD;
          }
     }
    val[u] = (sum * hashA + hashB) % MOD;
}

void compress() {
    diameter = -1;
    node = -1;

    dfs(1, 1, 0);

    diameter = -1;

    dfs(node, node, 0);

    int root;

    if(diameter % 2) {
	int cur = node;

	for(int k = 1; k <= diameter / 2; ++k)
	    cur = go[cur];

	int b = go[cur];

	root = n + 1;

	adj[root].clear();

	adj[root].push_back(b);
	adj[root].push_back(cur);
      
	adj[b].erase(find(adj[b].begin(), adj[b].end(), cur));
	adj[cur].erase(find(adj[cur].begin(), adj[cur].end(), b));
    }
    else {
	int cur = node;
		
	for(int k = 1; k <= diameter / 2; ++k)
	    cur = go[cur];

	root = cur;
    }

    reorder(root);
    
    dfs0(root, -1);
} 

vector<ll> cmp[2];

int main() {
    while(scanf("%d", &n) != EOF) {
	for(int k = 0; k < 2; ++k) {
	    cmp[k].clear();
	    for(int v = 1; v <= n; ++v) {
		adj[v].clear();
		deg[v] = 0;
		vec[v].clear();
	    }

	    for(int i = 1; i <= n - 1; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);

		adj[u].push_back(v);
		adj[v].push_back(u);
	    }

	    compress();
	    for (int v = 1; v <= n; v++) cmp[k].push_back(val[v]);
	    sort(cmp[k].begin(), cmp[k].end());
	}

	
	if(cmp[0] == cmp[1])
	    printf("S\n");
	else
	    printf("N\n");
    } 

    return 0;
}

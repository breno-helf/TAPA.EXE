#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pii edge;

#define pb push_back

const int MAX = 112345;
const int INF = 0x3f3f3f3f;

int T;
int n, m;
vector<int> adj[MAX];
vector<edge> resp;
map<edge, int> mrk;
int vis[MAX];
int cnt[MAX];
int low[MAX];
int curTime = 0;

void dfs(int u) {
    vis[u] = 1;
    cnt[u] = ++curTime;
    low[u] = curTime;
    
    edge backEdge = edge(-1, -1);
    int discoveryTime = INF;
    for (int v : adj[u]) {
	if (vis[v] == 0) {
	    mrk[edge(u, v)] = 1;
	    //printf("(%d) - Marking edge %d %d\n", u, u, v);
	    dfs(v);
	    low[u] = min(low[v], low[u]);
	} else if (vis[v] == 1) {
	    if (low[v] < discoveryTime) {
		backEdge = edge(u, v);
		discoveryTime = low[v];
	    }
	    low[u] = min(low[u], cnt[v]);		
	} else if (vis[v] == 2) {
	    if (low[v] < discoveryTime) {
		discoveryTime = low[v];
		backEdge = edge(u, v);
	    }
	}
    }

    
    //printf("(%d) - Marking backEdge %d %d (%d)\n", u, backEdge.first, backEdge.second, discoveryTime);
    mrk[backEdge] = 1;
    vis[u] = 2;
}

int main() {
    scanf("%d", &T);
    while (T--) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
	    int x, y;
	    scanf("%d %d", &x, &y);
	    adj[x].pb(y);
	    resp.pb(edge(x, y));
	}
	dfs(1);

	int removed = 0;
	
	for (auto& cur : resp) {
	    if (mrk[cur] == 0 && removed < (m - 2 * n)) {
		printf("%d %d\n", cur.first, cur.second);
		removed++;
	    }
	}
	
	mrk.clear();
	resp.clear();
	for (int i = 1; i <= n; i++) {
	    adj[i].clear();
	}
	memset(vis, 0, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));
	memset(low, 0, sizeof(low));
	curTime = 0;
    }
    return 0;
}

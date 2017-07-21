#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAX = 2 * 212345;
const int INF = 0x3f3f3f3f;

typedef pair<int, int> pii;

int n;
int m[MAX], r[MAX];
int d[MAX];

vector<pii> ans;
vector<pii> tot;

int win;

struct Edge {
    int to;
    int cap;
    Edge(int t, int c) { to = t; cap = c; }
};

vector<int> adj[MAX];
vector<Edge> edge;
vector<Edge> pre;
int ptr[MAX], dinic_dist[MAX];

inline void add_edge(int u, int v, int c) {
    adj[u].pb(edge.size());
    edge.pb(Edge(v, c));
    pre.pb(Edge(v, c));
    adj[v].pb(edge.size());
    edge.pb(Edge(u, 0));
    pre.pb(Edge(u, 0));
}

bool dinic_bfs(int _s, int _t) {
    memset(dinic_dist, -1, sizeof(dinic_dist));
    dinic_dist[_s] = 0;
    queue<int> q;
    q.push(_s);
    while(!q.empty() && dinic_dist[_t] == -1) {
	int v = q.front();
	q.pop();
	for (int a = 0; a < (int)adj[v].size(); a++) {
	    int ind = adj[v][a];
	    int nxt = edge[ind].to;
	    if (dinic_dist[nxt] == -1 && edge[ind].cap) {
		dinic_dist[nxt] = dinic_dist[v] + 1;
		q.push(nxt);
	    }
	}
    }
    return (dinic_dist[_t] != -1);
}

int dinic_dfs(int v, int _t, int flow) {
    if (v == _t) return flow;
    for (int &a = ptr[v]; a < (int)adj[v].size(); ++a) {
	int ind = adj[v][a];
	int nxt = edge[ind].to;
	if (dinic_dist[nxt] == dinic_dist[v] + 1 && edge[ind].cap) {
	    int got = dinic_dfs(nxt, _t, min(flow, edge[ind].cap));
	    if (got) {
		edge[ind].cap -= got;
		edge[ind ^ 1].cap += got;
		return got;
	    }
	}	
    }
    return 0;
}

int dinic (int _s, int _t) {
    int ret = 0, got;
    while (dinic_bfs(_s, _t)) {
	memset(ptr, 0, sizeof(ptr));
	while((got = dinic_dfs(_s, _t, INF))) ret += got;
    }
    return ret;
}

int solve () {
    int _s = 2e5 + 11;
    int _t = 2e5 + 12;
    for (int i = 0; i < n; i += 2) {
	add_edge(_s, i, 1);
    }
    for (int i = 1; i < n; i += 2) {
	add_edge(i, _t, 1);
    }
    for (auto e : tot) {
	if (e.first % 2) {
	    swap(e.first, e.second);
	}
	add_edge(e.first, e.second, 1);
    }
    
    // for (int i = 0; i < (int)edge.size(); i++) {
    //  	printf ("==> %d %d\n", edge[i].to, edge[i].cap);
    // }
    
    return dinic(_s, _t);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
	scanf("%d%d", m + i, r + i);
	d[i] = m[i] - r[i];
	if (d[i] > 0) win++;
    }

    for (int i = 0; i < (n - 1); i++) {
	int j = i + 1;
	if (d[i] > 0 && d[j] > 0) continue;
	if (((d[i] > 0 && d[j] < 0) || (d[i] < 0 && d[j] > 0)) && (d[i] + d[j] <= 0)) continue;
	tot.pb(pii(i, i + 1));
    }

    
    
    int flow;
    flow = solve();
    //printf ("%d\n", flow);


    // for (int i = 0; i < (int)edge.size(); i++) {
    //  	printf ("--> %d %d\n", edge[i].to, edge[i].cap);
    // }
    
    

    if (win > n/2) printf("0\n");
    else {
	vector<pii> can;
	for (int i = 0; i < (int)edge.size(); i += 2) {
	    //printf ("-- %d %d\n", pre[i].cap, edge[i].cap); 
	    if (edge[i].cap != pre[i].cap) {
		int lim = 2e5 + 10;
		int u = edge[i].to;
		int v = edge[i ^ 1].to;
		if (u < lim && v < lim) can.pb(pii(u, v));
	    }
	}
	
	while (!(win > n/2) && (int)can.size() > 0) {
	    pii cur = can.back();
	    can.pop_back();
	    ans.pb(cur);
	    n--;
	}

	if (!(win > n / 2)) printf("-1\n");
	else {
	    printf("%d\n", (int)ans.size());
	    for (auto e : ans) {
		printf("%d %d\n", e.first + 1, e.second + 1);
	    }
	}
    }

    return 0;
}

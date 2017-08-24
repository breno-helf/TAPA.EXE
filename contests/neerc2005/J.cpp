#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define debug(args...) fprintf(stderr, args);
typedef long long ll;
typedef ll FTYPE;

const ll INF = 0x3f3f3f3f;
const int MAX = 412;
const int MAXV = 4 * MAX * MAX;// Max vertices
const FTYPE FINF = INF;

int n;
ll m;
ll A[MAX], B[MAX];
map<int, pll> val;
vector<int> D[MAX];
int ans[MAX];
int cur = 0;

struct Edge {
    int to;
    FTYPE cap;
    int id;
    Edge(int t, int ID, FTYPE c) { to = t; id = ID; cap = c; }    
};

vector<int> adj[MAXV];
vector<Edge> edge;
int ptr[MAXV], dinic_dist[MAXV];
int S, T;

inline void add_edge(int u, int v, int id, FTYPE c) {
    adj[u].pb(edge.size());
    edge.pb(Edge(v, id, c));
    adj[v].pb(edge.size());
    edge.pb(Edge(u, id, 0));
}

bool dinic_bfs(int _s, int _t) {
    memset(dinic_dist, -1, sizeof(dinic_dist));
    dinic_dist[_s] = 0;
    queue<int> q;
    q.push(_s);

    while (!q.empty() && dinic_dist[_t] == -1) {
	int v = q.front();
	q.pop();
	for (size_t a = 0; a < adj[v].size(); a++) {
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

FTYPE dinic_dfs(int v, int _t, FTYPE flow) {
    if (v == _t) return flow;
    for (int &a = ptr[v]; a < (int)adj[v].size(); a++) {
	int ind = adj[v][a];
	int nxt = edge[ind].to;
	if (dinic_dist[nxt] == dinic_dist[v] + 1 && edge[ind].cap) {
	    FTYPE got = dinic_dfs(nxt, _t, min(flow, edge[ind].cap));
	    if (got) {
		edge[ind].cap -= got;
		edge[ind ^ 1].cap += got;
		return got;
	    }
	}
    }
    return 0;
}

FTYPE dinic(int _s, int _t) {
    FTYPE ret = 0, got;
    while (dinic_bfs(_s, _t)) {
	memset(ptr, 0, sizeof(ptr));
	while((got = dinic_dfs(_s, _t, INF))) ret += got;
    }
    return ret;
}

void build() {
    for (int k = 1; k <= min(300LL, m); k++) {
	add_edge(S, k, -1, 1);
	debug("%d --> %d\n", S, k);
    }

    for (auto e : val) {
	add_edge(e.first, T, -1, 1);
	debug("%d --> %d\n", e.first, T);
    }   
}

int main() {
    scanf("%d%lld", &n, &m);
    cur = 312;
    for (int i = 1; i <= n; i++) {
	scanf("%lld%lld", A + i, B + i);
	for (ll k = 1; k <= min(m,300LL); k++) {
	    ll g = k * A[i] + B[i];
	    if (nod.find(g) == nod.end()) {
		nod[g] = cur;
		val[cur++] = g;
	    }
	    add_edge(k, nod[g], i, 1);
	    debug("%d --> %d\n", (int)k, (int)g);
	}	
    }

    S = 0;
    T = MAXV - 3;
    
    build();

    debug("Ta indo?\n");
    ll flow = dinic(S, T);
    printf("Ta! %lld\n", flow);
    for(int u = 1; u <= min(300LL, m); u++){
	
    }
    for (int u = 1; u <= min(300LL, m); u++) {
	debug("==: %d\n", u);
	for (int a = 0; a < (int)adj[u].size(); a++) {
	    Edge ed1 = edge[adj[u][a]];
	    debug ("--> %d %d %d\n", (int)val[ed1.to], ed1.id, (int)ed1.cap);
	    if (ed1.cap <= 0 && ed1.id > 0) {
		ans[ed1.id] = u;
	    }
	}
	debug("\n");
    }

    for (int i = 1; i <= n; i++) {
	printf("%d ", ans[i]);
    }
    printf("\n");
}

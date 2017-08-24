#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define debug(args...) fprintf(stderr, args);
typedef long long ll;
typedef ll FTYPE;

const ll INF = 1e18;
const int MAX = 612;

int n, k;
ll p;
vector<int> D[MAX];
map<int, int> dente, id;
ll B[MAX], A[MAX];
int S, T;

// Dinic maxflow, min(O(EV^2),O(maxflow*E)(?)) worst case
// O(E*min(V^2/3,sqrt(E))) for unit caps (O(E*sqrt(V)) if bipartite)

typedef ll FTYPE;
// define as needed

const int MAXV = 1e5 + 10; // maximo numero de vertices
const FTYPE FINF = INF; // infinite flow

struct Edge {
    int to;
    FTYPE cap;
    Edge(int t, FTYPE c) { to = t; cap = c; }
};

vector<int> adj[MAXV];
vector<Edge> edge;
int ptr[MAXV], dinic_dist[MAXV];

// Inserts an edge u->v with capacity c
inline void add_edge(int u,int v,FTYPE c) {
    adj[u].push_back(edge.size());
    edge.push_back(Edge(v,c));
    adj[v].push_back(edge.size());
    edge.push_back(Edge(u,0)); // modify to Edge(u,c) if graph is non-directed
}

bool dinic_bfs(int _s,int _t) {
    memset(dinic_dist,-1,sizeof(dinic_dist));
    dinic_dist[_s] = 0;
    queue<int> q;
    q.push(_s);
    while(!q.empty() && dinic_dist[_t] == -1) {
	int v = q.front();
	q.pop();
	for(size_t a=0;a<adj[v].size();++a) {
	    int ind = adj[v][a];
	    int nxt = edge[ind].to;
	    if(dinic_dist[nxt] == -1 && edge[ind].cap) {
		dinic_dist[nxt] = dinic_dist[v] + 1;
		q.push(nxt);
	    }
	}
    }
    return dinic_dist[_t] != -1;
}

FTYPE dinic_dfs(int v,int _t,FTYPE flow) {
    if(v == _t) return flow;
    for(int &a = ptr[v];a<(int)adj[v].size();++a) {
	int ind = adj[v][a];
	int nxt = edge[ind].to;
	if(dinic_dist[nxt] == dinic_dist[v] + 1 && edge[ind].cap) {
	    FTYPE got = dinic_dfs(nxt,_t,min(flow,edge[ind].cap));
	    if(got) {
		edge[ind].cap -= got;
		edge[ind^1].cap += got;
		return got;
	    }
	}
    }
    return 0;
}

FTYPE dinic(int _s,int _t) {
    FTYPE ret = 0, got;
    while(dinic_bfs(_s,_t)) {
	memset(ptr,0,sizeof(ptr));
	while((got = dinic_dfs(_s,_t, INF))) ret += got;
    }
    return ret;
}

// Clears dinic structure
inline void dinic_clear() {
    for(int a=0;a<MAXV;++a) adj[a].clear();
    edge.clear();
}

void build() {
    int cur = k + 10;
    for (int i = 1; i <= k; i++) {
	add_edge(S, i, B[i]);
	debug("adding edge Source --> %d (%lld)\n", i, B[i]);
	for (int d : D[i]) {
	    if (dente.find(d) == dente.end()) {
		id[cur] = d;
		dente[d] = cur++;
	    }
	    debug("adding edge %d --> (%d, %d) (%lld)\n", i, d, dente[d], A[d]);
	    add_edge(i, dente[d], A[d]);
	}
    }
    for (int i = 1; i <= n; i++) {
	debug("adding edge (%d, %d) --> End (%d)\n", i, dente[i], 1);
	add_edge(dente[i], T, 1);
    }
}

int main() {
    scanf("%d%d%lld\n", &n, &k, &p);
    debug("--> %lld\n", p);
    for (int i = 1; i <= k; i++) {
	scanf("%lld", B + i);
    }
    for (int i = 1; i <= n; i++) {
	ll c;
	scanf("%lld%lld\n", &A[i], &c);
	D[c].pb(i);
    }
    vector<int> ans;
    S = MAXV - 3;
    T = MAXV - 4;
    build();
    printf("%lld\n", dinic(S, T));

    for (int i = 0; i < (int)edge.size(); i += 2) {
	Edge E = edge[i];
	Edge E2 = edge[i + 1];
	printf("--> %d %d (%lld %lld)\n", E2.to, E.to, E2.cap, E.cap);
    }
    
    for (int i = 1; i <= n; i++) {
	//debug("==: %d\n", dente[i]);
	for (int a = 0; a < (int)adj[dente[i]].size(); a++) {
	    Edge ed1 = edge[adj[dente[i]][a]];
	    //debug("--> %d %lld\n", ed1.to, ed1.cap);
	    if (ed1.to == T && ed1.cap == 0) {
		ans.pb(i);
	    }
	}
	//debug("\n");
    }
    for (int a : ans) {
	printf("%d ", a);
    }
    printf("\n");
}

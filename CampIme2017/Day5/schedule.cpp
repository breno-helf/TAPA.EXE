//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

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
int n, m;
vector<int> aula[MAX];

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


FTYPE faz (int x) {
    for (int i = 1; i <= n; i++) {
	add_edge(0, i, x);
    }
    for (int i = 1; i <= n; i++) {
	for (int a : aula[i]) {
	    add_edge(i, n + a, 1);
	}
    }
    
    for (int i = 1; i <= m; i++) {
	add_edge(n + i, (int)1e5 + 1, 1);
    }

    ll FLOW = dinic(0, (int)1e5 + 1);
    dinic_clear();
    return FLOW;
}

bool tenta (int x) {
    ll FLOW = faz(x);
    if (FLOW < x * n) return 0;
    return 1;
}

int main () {
    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
	int k;
	scanf ("%d", &k);
	for (int j = 0; j < k; j++) {
	    int a;
	    scanf ("%d", &a);
	    aula[i].pb(a);
	}
    }
    
    if (tenta(1) == false) {
	ll flow = faz(1);
	printf ("NO %lld\n", flow);
    } else {
	int l = 0, r = 1e5 + 1;
	while (l < r) {
	    int mid = (l + r + 1) / 2;
	    if (tenta(mid)) l = mid;
	    else r = mid - 1;
	}
	printf ("YES %d\n", l);
    }
    
    return 0;
}

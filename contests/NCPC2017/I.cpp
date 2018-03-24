#include<bits/stdc++.h>
using namespace std;

#define pb push_back

typedef pair<int, int> pii;

const int MAX = 512;
const int INF = 0x3f3f3f3f;

struct edge {
    int u, v;
    edge(int U = 0, int V = 0):
	u(U), v(V) {}

    bool operator < (const edge ot) const {
	return u < ot.u;
    }
};

int n;
vector<int> adj[MAX], rev[MAX];
vector<edge> edges;
unordered_map<string, int> M;
unordered_map<int, string> name;
int dist[MAX], prv[MAX];
edge invalid;
vector<int> shortest;
edge short_cyc;

int bfs(int st) {
    memset(dist, INF, sizeof(dist));
    dist[st] = 0;
    queue<int> Q;
    Q.push(st);

    while (!Q.empty()) {
	int u = Q.front();
	Q.pop();
	
	for (int i = 0; i < (int)adj[u].size(); i++) {
	    int v = adj[u][i];
	    if (u == invalid.u && v == invalid.v) {
		continue;
	    }
	    if (v == st) return u;
	    if (dist[u] + 1 < dist[v]) {
		if (dist[v] == INF) Q.push(v);
		dist[v] = dist[u] + 1;
		prv[v] = u;
	    }
	}
    }
    return -1;
}

void rebuild_cycle(int u, int v) {
    int cur = u;
    int cnt = 0;
    invalid = edge(u, v);
    	
    bfs(v);


    while(cur != v) {
	cnt++;
	shortest.pb(cur);
	cur = prv[cur];
	if (cnt > 510) assert(false);
    }
    shortest.pb(v);
    reverse(shortest.begin(), shortest.end());
}

void add_edge(int u, int v) {
    edges.pb(edge(u, v));
    adj[u].pb(v);
    rev[v].pb(u);
    if (v == u) {
	cout << name[v] << '\n';
	exit(0);
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
	string s;
	cin >> s;
	M[s] = i;
	name[i] = s;
    }

    for (int i = 1; i <= n; i++) {
	string s;
	int m;
	cin >> s >> m;
	//assert(i == M[s]);
	for (int j = 0; j < m; j++) {
	    string file, str = "";
	    cin >> file;
	    getline(cin, file);
	    for (int k = 0; k < (int)file.size(); k++) {
		if (file[k] == ' ' || file[k] == '\n') continue;
		if (file[k] == ',') {
		    add_edge(i, M[str]);
		    str = "";
		} else str += file[k];
	    }
	    add_edge(i, M[str]);
	}
    }

    int cyc_size = INF;
    
    for (int v = 1; v <= n; v++) {
	int u = bfs(v);
	if (u == -1) continue;
	
	if (dist[u] + 1 < cyc_size) {
	    cyc_size = dist[u] + 1;
	    short_cyc.u = u;
	    short_cyc.v = v;
	}
    }

    if (cyc_size == INF) {
	cout << "SHIP IT\n";
    } else {
	int u = short_cyc.u;
	int v = short_cyc.v;
	rebuild_cycle(u, v);

	for (int i = 0; i < (int)shortest.size(); i++) {
	    cout << name[shortest[i]];
	    if (i != ((int)shortest.size() - 1)) cout << " ";
	}
	cout << '\n';
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAX = 1e5 + 10;

int k, c;
vector<int> adj[22][MAX];
double p[22], a[22];
int dist[2][MAX];
int V, sz[22];
int mx = 0;

double dp[22];

void dfs(int id, int u, int P, int d) {
    for (auto v : adj[id][u]) {
	if (v != P) {
	    dist[d][v] = dist[d][u] + 1;
	    if (dist[d][v] > mx) {
		V = v;
		mx = dist[d][v];
	    }
	    dfs(id, v, u, d);
	}
    }
}

void calc(int id) {
    mx = 0;
    dist[0][1] = 0;
    dfs(id, 1, -1, 0);
    mx = 0;
    dist[1][V] = 0;
    dfs(id, V, -1, 1);
    mx = 0;
    dist[0][V] = 0;
    dfs(id, V, -1, 0);
    double cnt = 0;
    for (int i = 1; i <= sz[id]; i++) {
	if (max(dist[0][i], dist[1][i]) <= k) cnt++;
    }
    p[id] = cnt / (double)sz[id];
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
	scanf("%d%d", &c, &k);

	a[0] = 1.0;
	
	for (int i = 1; i <= c; i++) {
	    int n;
	    scanf("%d", &n);
	    sz[i] = n;
	    for (int j = 1; j <= n; j++) adj[i][j].clear();
	    for (int j = 2; j <= n; j++) {
		int u;
		scanf("%d", &u);
		adj[i][j].pb(u);
		adj[i][u].pb(j);
	    }
	    calc(i);
	    a[i] = a[i - 1] * p[i];
	}
	double resp = c * a[c];
	for (int i = 1; i <= c; i++) {
	    resp += (3 + i) * (1 - p[i]) * a[i - 1];
	    //printf("%.3lf -- %.3lf\n", p[i], a[i]);
	}
	
	printf("%.6lf\n", resp / a[c]);
    }
}

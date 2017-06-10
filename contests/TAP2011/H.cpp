#include<bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr, args)
#define pb push_back

typedef pair<long double, long double> pdd;
typedef pair<int, long double> pid;

const int MAX = 112;
const long double INF = 1e16;
const long double EPS = 1e-9;

int n;
pdd P, L;
pdd C[MAX];
long double r[MAX];
long double dist[MAX];
map<pdd, int> M;
int mrk[MAX];
vector<pid> adj[MAX];

long double q (long double k) {
  return k * k;
}

long double calc (pdd a, pdd b) {
  return sqrt(q(a.first - b.first) + q(a.second - b.second)) + EPS;
}

int main () {
  while (true) {
    cin >> n >> P.first >> P.second >> L.first >> L.second;
    if (n == -1) break;
    M.clear();
    memset(mrk, 0, sizeof(mrk));
    for (int i = 0; i <= (n + 1); i++) adj[i].clear();
    
    M[P] = 0;
    M[L] = n + 1;
    for (int i = 1; i <= n; i++) {
      cin >> C[i].first >> C[i].second >> r[i];
      M[C[i]] = i;
    }

    adj[0].pb(pid(n + 1, calc(P, L)));
    
    for (int i = 1; i <= n; i++) {
      adj[0].pb(pid(i, calc(P, C[i])));

      adj[i].pb(pid(n + 1, min(calc(L, C[i]), abs(calc(L, C[i]) - r[i]))));
    }

    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
	adj[i].pb(pid(j, min(calc(C[i], C[j]), abs(calc(C[i], C[j]) - r[i]))));
	adj[j].pb(pid(i, min(calc(C[i], C[j]), abs(calc(C[i], C[j]) - r[j]))));
      }
    }

    for (int i = 0; i <= (n + 1); i++) {
      debug ("Arestas de %d\n----------------\n", i);
      for (auto e : adj[i]) {
	debug ("%d --> %d (%.3lf)\n", i, e.first, e.second);
      }
    }
    
    priority_queue<pid, vector<pid>, greater<pid> > Q;
    Q.push(pid(0.0, 0));
    for (int i = 1; i <= (n + 1); i++) dist[i] = INF;
    
    dist[0] = 0;
    while (!Q.empty()) {
      int u = Q.top().second;

      debug ("Estou %d\n", u);
      Q.pop();

      if (mrk[u]) continue;

      mrk[u] = 1;
      
      if (u == (n + 1)) break;
      
      for (auto e : adj[u]) {
	int v = e.first;
	long double w = e.second;

	if (dist[u] + w < dist[v]) {
	    dist[v] = dist[u] + w;
	    Q.push(pid(dist[v], v));	    
	}
      }

    }

    cout << fixed << setprecision(2) << dist[n + 1] + EPS << '\n';
    
  }

  return 0;
}

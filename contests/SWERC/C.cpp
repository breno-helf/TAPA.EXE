//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,double> pii;
typedef pair<ll,ll> pll;

const int MAX = 212;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

struct place {
    int a, b, c;
    place (int A, int B, int C): a(A), b(B), c(C) {}
    place (): a(0), b(0), c(0) {}
    bool operator < (const place ot) const {
	return (a < ot.a);
    }
    bool operator == (const place ot) const {
	return (a == ot.a && b == ot.b && c == ot.c);
    }
};

inline ll qd(ll x) {
    return x * x;
}

ll dist[MAX];
vector<pii> adj[MAX];
int last[MAX];
int mrk[MAX];
int n, m;
int q;
place piso[MAX];

void dijkstra (int a, int b) {
    memset(dist, INF, sizeof(dist));
    memset(last, -1, sizeof(last));
    memset(mrk, 0, sizeof(mrk));
    set<pii> Q;
    dist[a] = 0;
    Q.insert(pii(0, a));

    while (!Q.empty()) {
	int u = Q.begin()->second;
	mrk[u] = 1;
	Q.erase(Q.begin());
	
	for (auto e : adj[u]) {
	    int v = e.first;
	    int w = e.second;

	    if (dist[u] + w < dist[v]) {
		if (dist[v] == INF) {
		    dist[v] = dist[u] + w;
		    Q.insert(pii(dist[v], v));
		} else {
		    Q.erase(pii(dist[v], v));
		    dist[v] = dist[u] + w;
		    Q.insert(pii(dist[v], v));
		}

		last[v] = u;
	    }
	}	
    }
    
}

double euclidean (place a, place b) {
    return sqrt(qd(a.b - b.b) + qd(a.c - b.c));
}

int main () {    
    scanf ("%d %d", &n, &m);
    
    for (int i = 0; i < n; i++) {
	int a, b, c;
	scanf ("%d%d%d", &a, &b, &c);
	piso[i] = place(a, b, c);
    }
    
    for (int i = 0; i < m; i++) {
	int x, y;
	char s[50];
	scanf (" %d%d %s", &x, &y, s);
	if (s[0] == 'w') {
	    // Euclidean distance
	    adj[x].pb(pii(y, euclidean(piso[x], piso[y])));
	    adj[y].pb(pii(x, euclidean(piso[x], piso[y])));
	} else if (s[0] == 's') {
	    place a = piso[x];
	    place b = piso[y];
	    
	    adj[x].pb(pii(y, euclidean(piso[x], piso[y]) + 5 * abs(a.a - b.a)));
	    adj[y].pb(pii(x, euclidean(piso[x], piso[y]) + 5 * abs(a.a - b.a)));
	}else if (s[0] == 'l') {
	    // Custo 1 conecta mesmo ponto de andares diferentes
	    adj[x].pb(pii(y, 1));
	    adj[y].pb(pii(x, 1));
	} else if (s[0] == 'e') {
	    // x -> y custo 1, y -> x custo 3 * euclid
	    adj[x].pb(pii(y, 1));
	    adj[y].pb(pii(x, 3 * euclidean(piso[x], piso[y])));
	}
    }

    // for (int i = 0; i < n; i++) {
    // 	debug ("--> Edges of %d\n", i);
    // 	for (pii e : adj[i]) {
    // 	    debug ("(%d, %lf)\n", e.first, e.second);
    // 	}
    // 	debug("\n");
    // }
    
    scanf ("%d", &q);    
    while (q--) {
	int a, b;
	scanf ("%d %d", &a, &b);
        dijkstra(a, b);
	stack<int> resp;
	int cur = b;
	while (last[cur] != -1) {
	    resp.push(cur);
	    cur = last[cur];
	}
	printf ("%d ", a);
	while (!resp.empty()) {
	    printf ("%d ", resp.top());
	    resp.pop();
	}
	
	printf("\n");
    }
    return 0;
}





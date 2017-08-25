#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define debug(args...) fprintf(stderr, args)

const int MAX = 40;
typedef long double ld;
const ld eps = 1e-9;

inline int cmp(ld x, ld y = 0, ld tol = eps) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct point {
    ld x, y;
    point (ld X = 0, ld Y = 0): x(X), y(Y) {}
    point operator +(point q) { return point(x + q.x, y + q.y); }
    point operator -(point q) { return point(x - q.x, y - q.y); }
    point operator *(double t) { return point(x * t, y * t); }
    point operator /(double t) { return point(x/t, y/t); }

    double operator *(point q) { return (x * q.x + y * q.y); }
    double operator %(point q) { return (x * q.y - y * q.x); }
    double mod() { return sqrt(x * x + y * y); }


    int cmp(point q) const {
	if (int t = ::cmp(x, q.x)) return t;
	return ::cmp(y, q.y);
    }
};

//projeta o vetor v sobre o vetor u;
point proj(point v, point u) {
    return u * ((u * v) / (u*u));
}

// Calcula a distancia do ponto r ao segmento pq.
double seg_distance(point p, point q, point r) {
    point A = r - q, B = r - p, C = q - p;
    double a = A * A, b = B * B, c = C * C;
    if (cmp(b, a + c) >= 0) return sqrt(a);
    else if (cmp(a, b + c) >= 0) return sqrt(b);
    else return fabs(A % B) / sqrt(c);
}

// Calcula a distancia do ponto r ao segmento pq.
double seg_distance2(point p, point q, point r) {
    point A = r - q, B = r - p, C = q - p;
    double a = A * A, b = B * B, c = C * C;
    if (cmp(b, a + c) >= 0) return 0;
    else if (cmp(a, b + c) >= 0) return (p - q).mod();
    else return (proj(r - p, q - p) - p).mod();
}

vector<int> adj[MAX];
int n, mrk[MAX], can[MAX];
vector<point> red, blue;
point g;

void tenta(int a, int b) {
    if (a == b) return;
    double d = (red[a] - red[b]).mod();
    //debug("--> %d %d\n", a, b);
    for (int i = 0; i < n; i++) {
	point e = proj(blue[i] - red[a], red[b] - red[a]);
	double d2 = seg_distance2(red[a], red[b], blue[i]);
	double d3 = seg_distance(red[a], red[b], blue[i]);
	//debug("%.3lf %.3lf\n", d2, d3 * 3);
	if (3 * d3 <= d2) return;
    }

    adj[a].pb(b);
}



void build() {
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	    tenta(i, j);
	}
	tenta(i, n);
    }   
}

void dfs(int u) {
    mrk[u] = 1;
    for (auto v : adj[u]) {
	if (!mrk[v] && can[v]) {
	    dfs(v);
	}
    }
}


int main() {
    int t;
    for (int i = 0; i < MAX; i++) can[i] = 1;
    scanf("%d", &t);
    while(t--) {
	red.clear();
	blue.clear();
	for (int i = 0; i < MAX; i++) adj[i].clear();
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
	    ld x, y;
	    scanf("%LF%LF", &x, &y);
	    red.pb(point(x, y));
	}
	for (int i = 0; i < n; i++) {
	    ld x, y;
	    scanf("%LF%LF", &x, &y);
	    blue.pb(point(x, y));
	}

	ld x, y;
	scanf("%LF%LF", &x, &y);
	g = point(x, y);
	red.pb(g);
	
	build();
	// tenta(0, n);
	// for (int i = 0; i < n; i++) {
	//     printf("--> %d\n", i);
	//     for (auto v : adj[i]) printf("%d ", v);
	//     printf("\n");
	// }

	bool ok = true;
	
	for (int i = 1; i < n; i++) {
	    can[i] = 0;
	    memset(mrk, 0, sizeof(mrk));
	    dfs(0);
	    can[i] = 1;
	    if (mrk[n] == 0) {
		ok = false;
		break;
	    }
	}

	if (ok) puts("Goal");
	else puts("No goal");
    }
}

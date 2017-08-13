//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 52;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, m;
char g[MAX][MAX];
char s[MAX];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int dist[MAX][MAX][MAX];

struct st {
    int x, y, i, d;
    st(int X = 0, int Y = 0, int I = 0, int D = 0):
	x(X), y(Y), i(I), d(D) {}
    bool operator < (const st ot) const {
	if (d != ot.d) return d < ot.d;
	if (x != ot.x) return x < ot.x;
	if (y != ot.y) return y < ot.y;
	return i < ot.i;
    }
};

bool valid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}
    
int main() {
    map<char, int> M;

    M['L'] = 2;
    M['R'] = 0;
    M['U'] = 3;
    M['D'] = 1;
    
    memset(dist, INF, sizeof(dist));
    
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
	scanf(" %s", g[i]);
    scanf(" %s", s);

    int sz = strlen(s);
    int Ri, Rj, Ei, Ej;

    for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	    if (g[i][j] == 'R') {
		Ri = i;
		Rj = j;
	    } else if (g[i][j] == 'E') {
		Ei = i;
		Ej = j;
	    }
	}
    }
    
    set<st> Q;
    Q.insert(st(Ri, Rj, 0, 0));
    dist[Ri][Rj][0] = 0;

    //debug("==> %d %d\n", Ei, Ej);
    
    while (!Q.empty()) {
	st u = *Q.begin();
	Q.erase(u);
	int x = u.x;
	int y = u.y;
	int id = u.i;
	//debug("--> (%d, %d) (%d, %d, %d)\n", dist[x][y][id], u.d, x, y, id);

	//debug("%s \n", (Q.find(st(0, 2, 2, 1)) != Q.end()) ? "Esta!" : "Nao");
	
	if (x == Ei && y == Ej) break;
	
	for (int k = 0; k < 4; k++) {
	    int Nx = x + dx[k];
	    int Ny = y + dy[k];
	    if (!valid(Nx, Ny)) continue;
	    if (g[Nx][Ny] == '#') continue;
	    
	    if (dist[x][y][id] + 1 < dist[Nx][Ny][id]) {
		//debug("    Adding (%d, %d, %d) -- %d => %d\n", Nx, Ny, id, dist[Nx][Ny][id], dist[x][y][id] + 1);
		if (dist[Nx][Ny][id] != INF) {
		    Q.erase(st(Nx, Ny, id, dist[Nx][Ny][id]));
		    dist[Nx][Ny][id] = dist[x][y][id] + 1;
		    Q.insert(st(Nx, Ny, id, dist[Nx][Ny][id]));
		} else {
		    dist[Nx][Ny][id] = dist[x][y][id] + 1;
		    Q.insert(st(Nx, Ny, id, dist[Nx][Ny][id]));
		}
	    }
	}
	
	int Nx = -INF;
	int Ny = -INF;
	if (id < sz) {
	    Nx = x + dx[M[s[id]]];
	    Ny = y + dy[M[s[id]]];
	}

	if (valid(Nx, Ny) && g[Nx][Ny] != '#') {
	    if (dist[x][y][id] < dist[Nx][Ny][id + 1]) {
		//debug("    Adding2 (%d, %d, %d) -- %d => %d\n", Nx, Ny, id + 1, dist[Nx][Ny][id + 1], dist[x][y][id]);
		if (dist[Nx][Ny][id + 1] != INF) {
		    Q.erase(st(Nx, Ny, id + 1, dist[Nx][Ny][id + 1]));
		    dist[Nx][Ny][id + 1] = dist[x][y][id];
		    Q.insert(st(Nx, Ny, id + 1, dist[Nx][Ny][id + 1]));
		} else {
		    dist[Nx][Ny][id + 1] = dist[x][y][id];
		    Q.insert(st(Nx, Ny, id + 1, dist[Nx][Ny][id + 1]));
		}		
	    }	    
	} else if (Nx != -INF) {
	    if (dist[x][y][id] < dist[x][y][id + 1]) {
		if (dist[x][y][id + 1] != INF) {
		    Q.erase(st(x, y, id + 1, dist[x][y][id + 1]));
		    dist[x][y][id + 1] = dist[x][y][id];
		    Q.insert(st(x, y, id + 1, dist[x][y][id + 1]));
		} else {
		    dist[x][y][id + 1] = dist[x][y][id];
		    Q.insert(st(x, y, id + 1, dist[x][y][id + 1]));
		}		
	    }	    
	}

	for (int i = id + 1; i <= sz; i++) {
	    if (dist[x][y][id] + i - id < dist[x][y][i]) {
		if (dist[x][y][i] != INF) {
		    Q.erase(st(x, y, i, dist[x][y][i]));
		    dist[x][y][i] = dist[x][y][id] + i - id;
		    Q.insert(st(x, y, i, dist[x][y][i]));
		} else {
		    dist[x][y][i] = dist[x][y][id] + i - id;
		    Q.insert(st(x, y, i, dist[x][y][i]));
		}		
	    }
	}
    }

    int resp = INF;

    for (int i = 0; i <= sz; i++) {
	resp = min(resp, dist[Ei][Ej][i]);
    }
    
    printf("%d\n", resp);
}


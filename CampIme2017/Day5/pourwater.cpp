#include<bits/stdc++.h>
using namespace std;

#define pb push_back

typedef pair<int, int> pii;

const int MAX = 40;



int n;
char s[MAX][MAX];
int dx[] = {+1, +1, +1};
int dy[] = {-1,  0, +1};

int mrk[MAX][MAX];
int deg[MAX][MAX];
vector<pii> adj[MAX][MAX];
vector<pii> E;
vector<pii> O;

int main () {
    scanf ("%d", &n);
    
    for (int i = 0; i < n; i++) {
	scanf (" %s", s[i]);
    }
    
    queue<pii> Q;
    for (int i = 1; i < n - 1; i++) {
	Q.push(pii(0, i));
	mrk[0][i] = 1;
    }
    
    while (!Q.empty()) {
	pii u = Q.front();
	
	int i = u.first;
	int j = u.second;

	E.pb(u);
	
	for (int k = 0; k < 3; k++) {
	    int x = i + dx[k];
	    int y = j + dy[k];

	    if (x < 0 || x >= n || y < 0 || y >= n) continue;
	    if (s[x][y] == '#') continue;
	    if (!mrk[x][y]) {
		Q.push(pii(x, y));
		mrk[x][y] = 1;
	    }
	    adj[x][y].pb(pii(i, j));
	    deg[i][j]++;
	}
	Q.pop();
    }
    
    for (pii e : E) {
	int i = e.first;
	int j = e.second;
	
	if (!deg[i][j]) Q.push(pii(i, j));
    }
    
    while (!Q.empty()) {
	pii u = Q.front();
	O.pb(u);
	int i = u.first;
	int j = u.second;

	for (pii v : adj[i][j]) {
	    int x = v.first;
	    int y = v.second;
	    
	    deg[x][y]--;
	    if (!deg[x][y]) Q.push(pii(x, y));
	}
	Q.pop();
    }
    int x;
    scanf ("%d", &x);
    int tam = min(x, (int)O.size());
    for (int k = 0; k < tam; k++) {
	pii u = O[k];
	int i = u.first;
	int j = u.second;

	s[i][j] = '*';
    }

    for (int i = 0; i < n; i++) {
	printf ("%s\n", s[i]);
    }

    return 0;
}

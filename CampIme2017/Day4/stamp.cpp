#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAX = 1123;

typedef pair<int, int> pii;

int n, m;
int Xini, Xfim;
int Yini, Yfim;
char cur[MAX][MAX], final[MAX][MAX];
char st[MAX][MAX];
int Lx, Ly;
vector<pii> E;

void arruma () {
    while (Xfim > Xini) {
	bool tira = true;
	for (int i = 0; i < Yfim; i++) {
	    if (st[Xfim - 1][i] == 'x') tira = false;
	}
	if (!tira) break;
	Xfim--;
    }

    while (Xini < Xfim) {
	bool tira = true;
	for (int i = 0; i < Yfim; i++) {
	    if (st[Xini][i] == 'x') tira = false;
	}
	if (!tira) break;
	Xini++;
    }

    
    while (Yfim > Yini) {
	bool tira = true;
	for (int i = Xini; i < Xfim; i++) {
	    if (st[i][Yfim - 1] == 'x') tira = false;
	}
	if (!tira) break;
	Yfim--;
    }
    
    while (Yini < Yfim) {
	bool tira = true;
	for (int i = Xini; i < Xfim; i++) {
	    if (st[i][Yini] == 'x') tira = false;
	}
	if (!tira) break;
	Yini++;
    }
}

bool estampa (int x, int y) {
    //printf ("===> %d %d\n", x, y);
    int dx = x - E[0].first;
    int dy = y - E[0].second;
    for (auto e : E) {
	int i = e.first, j = e.second;
	//printf ("--> %d %d\n", dx + i, dy + j);
	if ((dx + i) < 0 || (dy + j) < 0 || (i + dx) >= n || (j + dy) >= m) return false;

	if(final[i + dx][j + dy] == 'x') final[i + dx][j + dy] = '.';
	else final[i + dx][j + dy] = 'x';
    }
    return true;
}

bool solve () {
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	    if (final[i][j] == 'x') {
		if (!estampa(i, j)) {
		    return false;
		}
	    }
	}
    }
    return true;
}

int main () {
    int t;
    scanf ("%d", &t);

    while (t--) {
	scanf ("%d %d %d %d", &n, &m, &Xfim, &Yfim);
	Xini = Yini = 0;
	Lx = Ly = -1;
	E.clear();
	memset(cur, '.', sizeof(cur));
	
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < m; j++) {
		scanf(" %c", &final[i][j]);
	    }
	}
	
	for (int i = 0; i < Xfim; i++) {
	    for (int j = 0; j < Yfim; j++) {
		scanf (" %c", &st[i][j]);
	    }
	}
	
	arruma();
	for (int i = Xini; i < Xfim; i++) {
	    for (int j = Yini; j < Yfim; j++) {
		if (st[i][j] == 'x') E.pb(pii(i - Xini, j - Yini));
	    }
	}
	
	printf ("%s\n", solve() ? "ANO" : "NIE");
	
    }
    return 0;
}

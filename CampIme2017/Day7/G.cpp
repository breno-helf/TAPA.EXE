//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, m, k;

int g[MAX][MAX];
int L[MAX], C[MAX];
vector< pair<int, pii> > op;
void precomp () {
    op.clear();
    int it = 0;
    for (int i = 0; i < n; i++) {
	int sum = 0;
	for (int j = 0; j < m; j++) {
	    sum += g[i][j];
	}
	L[i] = sum;
    }
    
    for (int i = 0; i < m; i++) {
	int sum = 0;
	for (int j = 0; j < n; j++) {
	    sum += g[j][i];
	}
	C[i] = sum;
    }

    for (int i = 0; i < n; i++) {
	int mn = INF;
	for (int j = 0; j < m; j++) {
	    mn = min(mn, C[j] + ((g[i][j] == 0) ? 1 : -1));
	}
	op.pb(mp(L[i], pii(mn, it++)));
    }
    
    for (int i = 0; i < m; i++) {
	int mn = INF;
	for (int j = 0; j < n; j++) {
	    mn = min(mn, L[j] + ((g[j][i] == 0) ? 1 : -1));
	}
	op.pb(mp(C[i], pii(mn, it++)));
    }
    
    sort(op.begin(), op.end());
}

int main () {
    int t;
    scanf ("%d", &t);
    while (t--) {
	scanf ("%d%d", &n, &m);
	scanf ("%d", &k);
	
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < m; j++) {
		char c;
		scanf (" %c", &c);
		if (c == '.') g[i][j] = 0;
		else if (c == '*') g[i][j] = 1;
	    }
	}
	
	while (k--) {
	    precomp();
	    pair<int, pii> O = op[0];
	    int j = O.second.second;
	    // for (int i = 0; i < n; i++)
	    // 	debug ("--> %d %d\n", i, L[i]);
	    // for (int i = 0; i < m; i++)
	    // 	debug ("--> %d %d\n", i, C[i]);
	    
	    // debug ("%d %d %d\n", O.first, O.second.first, j); 
	    if (j < n) {
		for (int i = 0; i < m; i++) {
		    if (g[j][i] == 1) g[j][i] = 0;
		    else g[j][i] = 1;
		}
	    } else {
		for (int i = 0; i < n; i++) {
		    if (g[i][j - n] == 0) g[i][j - n] = 1;
		    else g[i][j - n] = 1;

		}
	    }
	}
	int resp = 0;
	for (int i  = 0; i < n; i++) {
	    for (int j = 0; j < m; j++) {
		if (g[i][j] == 1) resp++;
	    }
	}
	printf ("%d\n", resp);
    }
    return 0;
}



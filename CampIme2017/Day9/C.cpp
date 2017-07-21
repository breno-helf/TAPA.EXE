#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define debug(args...) //fprintf(stderr, args)

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 212;
const ll  MOD = (ll)1e9 + 7;

vector<pii> edges;
int adj[MAX][MAX];
int n, m;
ll memo[MAX][MAX];

ll cmb (ll p, ll q) {
    if (q == 0) return 1;

    if (q < 0) return 0;

    if (p < q) return 0;

    if (p == 0) return 1;
    
    ll &res = memo[p][q];
    if (res != -1) return res;


    return res = (cmb(p - 1, q) + cmb(p - 1, q - 1)) % MOD;
}

int main () {
    memset(memo, -1, sizeof(memo));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
	int a, b;
	scanf("%d%d", &a, &b);
	edges.pb(pii(a, b));
	adj[a][b] = 1;
	adj[b][a] = 1;
    }
    
    ll resp = 0;
    for (int i = 0; i < m; i++) {
	int a, b;
	a = edges[i].first;
	b = edges[i].second;
	
	ll Sa, Sb;
	ll S;
	Sa = Sb = S = 0;
	
	for (int j = 1; j <= n; j++) {
	    if (j == a || j == b) continue;
	    
	    if (adj[a][j] == 1 && adj[b][j] == 1) S++;
	    else if (adj[a][j] == 1 && adj[b][j] == 0) Sa++;
	    else if (adj[a][j] == 0 && adj[b][j] == 1) Sb++;
	}
	//printf ("%lld ---> %d %d %lld %lld %lld\n", resp, a, b, Sa, Sb, S);
	for (int k = 0; k <= 5; k++) {
	    ll qtd = cmb(S, k);
	    ll sum = 0;
	    if (qtd > 0) {
		for (int j = 0; j <= k; j++) {
		    //printf ("==> %lld %d %d\n", sum, j, k - j);
		    sum = (sum + cmb(k, j) * cmb(Sa, 3 - j) * cmb(Sb, 2 - (k - j))) % MOD;
		    sum = (sum + cmb(k, j) * cmb(Sa, 2 - j) * cmb(Sb, 3 - (k - j))) % MOD;
		}
	    }
	    resp = (resp + (sum * qtd) % MOD) % MOD;
	}
	
    }

    printf("%lld\n", resp % MOD);
    return 0;
}

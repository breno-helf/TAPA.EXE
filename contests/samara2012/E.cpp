//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 12313;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, m;
int v[22][62], tam[22];
int seen[62];
int resp;

int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
	scanf ("%d", &tam[i]);

	for (int j = 0; j < tam[i]; j++) {
	    scanf ("%d", &v[i][j]);
	}
    }
    resp = INF;
    int sz = 22;
    for (int bm = 1; bm < (1<<n); bm++) {
	if (__builtin_popcount(bm) >= sz) continue;
	int num = 0;
	for (int i = 0; i < n; i++) {
	    if ((bm & (1<<i)))
		for (int k = 0; k < tam[i]; k++)
		    if(seen[v[i][k]] != bm) {
			num++;
			seen[v[i][k]] = bm;
		    }
	}
	if (num == m) {
	    resp = bm;
	    sz = __builtin_popcount(bm);
	}
    }

    printf("%d\n", sz);
    
    for (int i = 0; i < n; i++) {
	if ((1<<i) & resp) printf("%d ", i + 1);
    }

    putchar('\n');
}


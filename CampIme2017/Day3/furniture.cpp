//If you are trying to hack me I wish you can get it, Good Luck :D.
#include "bits/stdc++.h"
using namespace std;

#define debug(args...) //fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 55;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n;
ll c[MAX];
int p[MAX], inv[MAX];
int mrk[MAX], seen[MAX];
ll resp = 0;
vector<int> inp;

pll dfs (int u) {
    seen[u] = 1;
    pll mx = pll(c[u], u);
    if (seen[p[u]] == 0) {
	mx = min(mx, dfs(p[u]));
    }
    return mx;
}

pll sum (int u) {
    mrk[u] = 1;
    pll ret = pll(c[u], 1LL);
    if (mrk[p[u]] == 0) {
	pll add = sum(p[u]);
	ret = pll(ret.first + add.first, ret.second + add.second);
    }
    return ret;
}

int main () {
    int cur;
    while (scanf ("%d", &cur) != EOF) {
	inp.pb(cur);
    }
    n = (int)inp.size() / 2;

    for (int i = 0; i < n; i++)
	c[i] = inp[i];    
    for (int i = n; i < 2 * n; i++) {
	p[i - n] = inp[i];
	inv[p[i - n]] = i - n;
    }

    vector<int> cmp;
    vector<pll> inf;
    ll mn = INF;
    for (int i = 0; i < n; i++) {
	if (!seen[i]) {
	    ll guy = dfs(i).second;
	    mn = min(mn, c[guy]);
	    debug ("--> %lld\n", guy);
	    cmp.pb(guy);
	    inf.pb(sum(guy));
	}
    }
    // 10 | 4
    // 0 -> 1 -> 0
    // min(62, --) + min(120, 31 + 62 + 31)
    debug ("--> %lld\n", mn);
    
    for (int i = 0; i < (int)cmp.size(); i++) {
	ll a = c[cmp[i]];
	ll b = inf[i].first, C = inf[i].second;

	ll A = b + (C - 2) * a;
	ll B = (b - a + mn) + (C - 2) * mn + 2 * (a + mn);
	resp += min(A, B);
    }
    
    printf ("%lld\n", resp);
}


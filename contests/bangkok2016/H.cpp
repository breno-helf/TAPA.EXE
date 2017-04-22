//If you are trying to hack me I wish you can get it, Good Luck :D
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

int dp[(1<<8) + 10][MAX][MAX];
int k, m, n;
int E[MAX], P[MAX];

int solve (int BM, int life, int tox) {
    int &res = dp[BM][life][tox];
    if (res != -1) return res;
    if (tox >= 100) return -INF;
    if (life <= k) return 0;
    int curL = life, curT = tox;
    curL -= k;
    curT -= m;
    curT = max(curT, 0);
    res = max(res, 1 + solve(BM, curL, curT));
    for (int i = 0; i < n; i++) {
	if (1<<i & BM) {
	    res = max(res, 1 + solve(BM - (1<<i), min(curL + E[i], 100), curT + P[i]));
	}
    }
    return res;
}

int main () {
    int t;
    for (scanf ("%d", &t); t; t--) {
	memset(dp, -1, sizeof(dp));
	scanf ("%d%d", &k, &m);
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
	    scanf ("%d", E + i);
	for (int i = 0; i < n; i++)
	    scanf ("%d", P + i);

	printf ("%d\n", solve((1<<n) - 1, 100, 0));
    }
    return 0;
}


//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 11234;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;
const int K = 200;

int n;
ll dp[MAX][512];
char s[MAX];

ll solve (int i, int c) {
    ll &res = dp[i][c];
    int h = c - K;
    if (i == n) return res = (c == K) ? 1LL : 0LL;
    
    if (res != -1) return res;
    
    int cur = s[i] + h;
    
    if (cur < 32 || cur > 126) return res = 0LL;

    res = 0;
    for (int k = cur; k <= 126; k += 31) {
	res = (res + solve (i + 1, K + (cur - k) / 31)) % MOD;
    }
    for (int k = (cur - 31); k >= 32; k -= 31) {
	res = (res + solve (i + 1, K + (cur - k) / 31)) % MOD;
    }
    return res;
}

int main () {
    memset(dp, -1, sizeof(dp));
    gets(s);
    n = strlen(s);
    reverse(s, s + n);
    printf ("%lld\n", solve(0, K) % MOD);
    return 0;
}

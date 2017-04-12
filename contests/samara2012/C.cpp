//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 212;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

ll dp[MAX][MAX];

ll solve (ll n, ll m) {
    if (m == 1) return n;
    if (n == m) return 1;
    ll &p = dp[n][m];
    if (p != -1) return p;
    p = (solve(n - 1, m - 1) + solve(n - 1, m)) % MOD;
    //debug("%lld %lld -- %lld\n", n, m, p);
    return p;
}

int main () {
    // freopen ("input.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
    cin.sync_with_stdio(false);
    memset(dp, -1, sizeof(dp));
    ll n, m;

    
    cin >> n >> m;
    if (m < n) cout << 0 << '\n';
    else if (n == m) cout << 1 << '\n';
    else cout << solve(m, n) << '\n';
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;
typedef pair<ll, ll> pll;

const ll INF = 1e17;
const int MAX = 1123456;

int n;
ll v[MAX], dp[MAX][7];
ll resp = 0;

ll solve (int i, int s) {
    if (i == n) {
	if (s == 0) return 0;
	else return -INF;
    }
    
    if (dp[i][s] != -1) return dp[i][s];

    return dp[i][s] = max(solve(i + 1, (s + v[i]) % 7) + v[i], solve(i + 1, s)); 
}

int main () {
    memset(dp, -1, sizeof(dp));
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
	ll a;
	scanf ("%lld", &a);
	v[i] = a;
    }

    resp = solve(0, 0);
    
    printf ("%lld\n", resp);
}

//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1123456;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

ll c[MAX];
int n;

int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) {
	scanf ("%lld", c + i);
    }
    ll resp = c[n] * n;
    for (int i = 1; i < n; i++) {
	if (c[i] < c[n])
	    resp += (n - i) * (c[i] - c[n]);
    }

    printf ("%lld\n", resp);
}


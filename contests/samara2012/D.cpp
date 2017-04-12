//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 12231;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

ll n, k;

ll fexp (ll a, int e) {
    ll pow = a, ret = 1;
    for (int i = 0; i < 30; i++) {
	if ((1<<i)&e) ret *= pow;
	pow *= pow;
    }
    //debug ("%lld %d -- %lld\n", a, e, ret);
    return ret;
}

int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    cin.sync_with_stdio(false);

    cin >> n >> k;
    int resp = 0;
    while (fexp(k + 1, resp) < n) resp++;
    cout << resp << '\n';
}


#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

const ll MOD = 1e9 + 7;

int n;
vector<ll> b;

int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) {
	ll p;
	scanf ("%lld", &p);
	b.pb(p);
    }
    ll resp = 1;
    sort(b.begin(), b.end());
    for (int k = n; k >= 1; k--) {
	ll num = b.end() - lower_bound(b.begin(), b.end(), (ll)k);
	if (num + (k - n) <= 0) resp = 0;
	else {
	    resp = (resp * (num + k - n)) % MOD;
	}
    }

    printf ("%lld\n", resp);
}

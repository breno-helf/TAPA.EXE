#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;
typedef pair<ll, ll> pll;

vector<pll> m;
int t;
ll n;

int main () {
    scanf ("%d", &t);
    while (t--) {
	scanf ("%lld", &n);
	
	for (int i = 0; i < n; i++) {
	    ll x, r;
	    scanf ("%lld %lld", &x, &r);
	    m.pb(pll(x, r));
	}

	for (int i = 0; i < n; i++) {
	    
	}
    }
}

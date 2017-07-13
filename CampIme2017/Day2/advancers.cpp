#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ll;

ll c[70];
int q, t, s;

bool ok (ll val) {
    ll sum = 0;
    for (int i = 0; i < t; i++) {
	sum += min(c[i], val);
    }
    //printf ("%llu\n", sum / s);
    sum /= s;
    if (sum >= val) return true;
    else return false;
}

ll solve () {
    ll l = 0, r = (ll)6e18;
    while (l < r) {
	ll mid = (r - l + 1) / 2 + l;
	if (ok(mid)) {
	    l = mid;
	} else {
	    r = mid - 1;
	}
    }
    return l;
}

int main () {
    scanf ("%d", &q);
    while (q--) {
	scanf ("%d %d", &t, &s);
	for (int i = 0; i < t; i++) {
	    scanf ("%llu", &c[i]);
	}
	printf ("%llu\n", solve());
    }    
}

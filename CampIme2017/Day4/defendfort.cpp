#include <bits/stdc++.h>
using namespace std;

const int MAX = 112345;

typedef long long ll;
typedef pair<ll, ll> pll;

ll d;
ll a[MAX], k[MAX];
int n;
set<pll> s;


int main () {
    scanf ("%d %lld", &n, &d);
    for (int i = 0; i < n; i++) {
	scanf ("%lld %lld", &a[i], &k[i]);
	k[i] = min(k[i], a[i]);
	s.insert(pll(- k[i], i));
    }
    
    
    
    while (d > 0 && !s.empty()) {
	auto it = s.begin();
	ll cur = it->second;
	//printf ("--> %lld\n", cur);
	s.erase(it);
	ll num = min(d, a[cur] / k[cur]);
	a[cur] = a[cur] - k[cur] * num;
	d -= num;
	if (a[cur] != 0) {
	    k[cur] = min(k[cur], a[cur]);
	    s.insert(pll(-k[cur], cur));
	}
    }

    ll resp = 0;
    
    for (int i = 0; i < n; i++) {
	resp += a[i];
    }

    printf ("%lld\n", resp);
}

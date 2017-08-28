#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N;

ll llrand() { ll a = rand(); a <<= 32; a += rand(); return a; }

ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : abs(b); }

ll mulmod(ll a, ll b, ll mod) {
    if (b < 0) return mulmod(a, (b%mod + mod) % mod, mod);
    if (b == 0) return 0LL;

    ll ans = (2LL * mulmod(a, b/2, mod)) % mod;

    if (b % 2 == 0) return ans;

    return (ans + a) % mod;
}

ll exp_mod(ll a, ll e, ll mod) {
    ll pow = a, ret = 1;

    for (int k = 0; k < 63; k++) {
	if ((1LL<<k) & e) ret = mulmod(ret, pow, mod);
	pow = mulmod(pow, pow, mod);
    }

    return ret;
}

int is_probably_prime(ll n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;

    ll s = 0, d = n- 1;

    while (d % 2 == 0) {
	d /= 2; s++;
    }

    for (int k = 0; k < 64; k++) {
	ll a = (llrand() % (n - 3)) + 2;
	ll x = exp_mod(a, d, n);
	//printf("--> (%lld %lld %lld) %lld\n", a, d, n, x);
	if (x != 1 && x != n-1) {
	    for (ll r = 1; r < s; r++) {
		x = mulmod(x, x, n);
		if (x == 1) return 0;
		if (x == n - 1) break;		
	    }

	    if (x != n-1) return 0;	    
	}	
    }
    return 1;
}

ll rho(ll n) {
    ll d, c = rand() % n, x = rand() % n, xx = x;
    
    if (n % 2 == 0)
	return 2;

    do {
	x = (mulmod(x, x, n) + c) % n;
	xx = (mulmod(xx, xx, n) + c) % n;
	xx = (mulmod(xx, xx, n) + c) % n;
	if (x > xx)
	    d = gcd(abs(x - xx), n);
	else d = gcd(abs(xx - x), n); 
	//printf("==> %lld\n", d);
    } while (d == 1);
    //printf("==> %lld\n", d);

    return d;
}

map<ll, ll> F;

void factor(ll n) {
    if (n == 1)
	return;
    if (is_probably_prime(n)) {
	F[n]++;
	return;
    }

    //printf("--> %lld\n", n);
    ll d = rho(n);
    factor(d);
    factor(n / d);
}

int main() {
    srand(time(NULL));
    scanf("%lld", &N);

    
    factor(N);
    
    ll resp = 1;

    for (auto e : F) {
	resp *= (e.second + 1);
    }

    printf("%lld\n", resp);
    return 0;
}

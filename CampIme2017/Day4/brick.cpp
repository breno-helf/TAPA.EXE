#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

ll a, b, c;

bool bb (ll A, ll B, ll C) {
    ll l = 0, r = A;
    while (l < r) {
	ll mid = (l + r) / 2;
	if (mid * B > C) r = mid - 1;
	else if (mid * B < C) l = mid + 1;
	else return true;
    }
    return false;
}

bool corta (ll A, ll B, ll C) {
    if (C < 0) return false;
    if (C == 0) return true;
    if (C % B == 0 && C / B <= A) return true;
    if (C % A == 0 && C / A <= B) return true;
    return false;
}

bool corta2 (ll A, ll B, ll C) {
    vector<ll> D;
    for (ll i = 1; i * i <= C; i++) {
	if (C % i == 0) {
	    D.pb(i);
	    D.pb(C / i);
	}
    }
    
    for (ll d : D) {
	if (d <= A) {
	    if (corta(d, B, C)) return true;
	}
    }
    return false;
}

int main () {
    int t;
    scanf ("%d", &t);
    while (t--) {
	int ans = 3;
	scanf ("%lld %lld %lld", &a, &b, &c);
	if (a * b == c || c == 0LL) ans = min(ans, 0);
	if (corta(a, b, c)) ans = min(ans, 1);
	if (corta2(a, b, c) || corta2(b, a, c) || corta(a - 1, b, c - a) || corta (a, 1, c - (a - 1) * b) || corta(b, 1, c - a * (b - 1)) || (corta(a, b - 1, c - b))) ans = min(ans, 2);
	printf("%d\n", ans);
    }
}

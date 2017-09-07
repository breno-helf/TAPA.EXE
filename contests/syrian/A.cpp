#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 112345;

int n;
ll L, R;

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
	scanf("%d", &n);
	L = 0;
	R = (ll)1e18;
	ll cur = 0;
	for (int i = 0; i < n; i++) {
	    ll m;
	    char c;
	    scanf(" %lld %c", &m, &c);
	    if (c == '+') {
		cur += m + 25LL;
		L = max(L, cur);
	    } else {
		R = min(R, m + cur + 25LL);
	    }
	}
	//printf("--> %lld %lld\n", L, R);
	printf("%lld\n", max(R - L, 0LL));
    }
    return 0;
}



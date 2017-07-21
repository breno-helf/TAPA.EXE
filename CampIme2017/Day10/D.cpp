#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;
typedef pair<ll, ll> pll;

vector<pll> low, high;

int n;
ll m;


int main() {
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
	ll a, b;
	scanf("%lld%lld", &a, &b);
	if (b == 1) low.pb(pll(a, i));
	else high.pb(pll(a, i));
    }

    sort(low.begin(), low.end());
    sort(high.begin(), high.end());

    int L = low.size();
    int H = high.size();
    
    ll sum = 0;
    int a, b;
    a = L - 1;
    b = H - 1;
    while (sum < m) {
	if (a < 0) {
	    sum += high[b].first;
	    b--;
	} else if (b < 0) {
	    sum += low[a].first;
	    a--;
	} else {
	    if (low[a] < high[b]) {
		sum += high[b].first;
		b--;
	    } else {
		sum += low[a].first;
		a--;
	    }
	}
    }

    
    while (a >= 0 && b < (H - 1)) {
	if ((sum - (high[b + 1].first) + (low[a].first)) < m) break;
	sum -= (high[b + 1].first);
	b++;
	sum += (low[a].first);
	a--;
    }
    
    printf ("%d %d\n", L - a + H - b - 2, L - a - 1);
    
    for (int i = a + 1; i < L; i++) {
	printf("%lld ", low[i].second);
    }
    for (int i = b + 1; i < H; i++) {
	printf("%lld ", high[i].second);
    }
    printf("\n");
}

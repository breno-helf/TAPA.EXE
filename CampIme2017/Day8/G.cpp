#include <bits/stdc++.h>
using namespace std;

const int MAX = 212345;
typedef long long ll;
const ll INF = 1e18;


int n;
ll a[MAX];
multiset<ll> s;

int main () {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
	scanf ("%lld", a + i);
	s.insert(a[i]);
    }
    s.insert(INF);
    ll resp = INF;

    for (int j = n - 1; j >= 0; j--) {
	auto it = s.find(a[j]);
	s.erase(it);
	it = s.upper_bound(a[j]);
	
	resp = min(resp, *it - a[j]);
    }
    
    printf("%lld\n", resp);
    return 0;
}

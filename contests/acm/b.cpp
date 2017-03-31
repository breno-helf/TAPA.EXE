#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

ll n, k, s, c1, c2, m;

int main () {
    int t;
    scanf("%d", &t);
    for (;t;t--) {
	scanf("%lld%lld%lld%lld%lld%lld", &n, &k, &s, &c1, &c2, &m);

	priority_queue<ll> Q;
	Q.push(s);
	for (int i = 1; i <= n; i++) {
	    s = (c1 * s + c2) % m;
	    Q.push(s);
	    if ((int)Q.size() > k) Q.pop();
	}
	vector<ll> v;
	while (!Q.empty()) {
	    v.pb(Q.top());
	    Q.pop();
	}
	reverse(v.begin(), v.end());
	for (auto e : v)
	    printf("%lld ", e);
	printf("\n");
    }

}

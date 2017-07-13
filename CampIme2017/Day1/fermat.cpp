#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define FOR(i,a,b) for(int i = a; i <= b; ++i)

typedef long long ll;
typedef pair<int, int> pii;

const ll INF = 1e17;
const int maxn = 250000 + 10;

int n, m;

ll fexp (int a, int e) {
    ll ret = 1, pow = a;
    for (int i = 0; i <= 30; i++){
			if (e & (1 << i)){
			    ret *= pow;
			    ret %= m;
			}
			pow *= pow;
			pow %= m;
    }
    return ret;
}

ll cnt[maxn];
vector<int>t;

int main () {
	scanf("%d%d",&n,&m);
	FOR(i,1,m-1) ++cnt[fexp(i,n)];
	FOR(i,1,m-1) if(cnt[i]) t.pb(i);

	cout << t.size() << '\n';

	ll ans = 0;
	
	FOR(i,1,m-1)
		FOR(j,1,m-1){
			if((i + j) % m == 0) continue;
			ll add = 6 * cnt[i] * cnt[j] * cnt[(i + j) % m];
			ans += add;
		}
		*/
	printf("%lld\n",ans);
  return 0;
}

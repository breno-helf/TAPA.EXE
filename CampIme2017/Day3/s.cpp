#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define REP(i,a,b) for(int i = a; i >= b; --i)
#define debug(args...) fprintf(stderr,args)

const int maxn = 1e6 + 10;

typedef long long ll;
typedef pair<ll,ll>pii;

int n;
ll c[maxn];

ll dis(int x, int y){
	return y - x + 1;
}

ll solve(){
	ll ans = 0;
	set<pii>s;
	FOR(i,1,n) s.insert(pii(c[i],i));
	REP(i,n,1){
		while(!s.empty() && s.begin()->second > i) s.erase(s.begin());
		ll C = s.begin()->first;
		ll pos = s.begin()->second;
		ans += C * dis(pos,i);
		i = pos;
	}
	return ans;
}

int main(){
	scanf("%d",&n);
	REP(i,n,1) scanf("%lld",&c[i]);
	printf("%lld\n",solve());
	return 0;
}
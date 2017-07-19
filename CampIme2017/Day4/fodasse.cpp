#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define FOR(i,a,b) for(int i = a; i <= b; ++i)

typedef long long ll;
typedef pair<ll,ll>pii;

int n;
ll d;
vector<pii>vec;

bool cmp(pii a, pii b){
	return a.second > b.second;
}

ll solve(){
	ll ans = 0;

	return ans;
}

int main(){
	scanf("%d%lld",&n,&d);
	for(int i = 0; i < n; ++i){
		ll a, k;
		scanf("%lld%lld",&a,&k);
		vec.pb(pii(a,k));
	}
	printf("%lld\n",solve());
	return 0;	
}
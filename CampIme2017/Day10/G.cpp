#include "bits//stdc++.h"
using namespace std;

#define pb push_back
#define debug(args...) //fprintf(stderr,args);
typedef long long ll;
typedef pair<int,ll>pii;
const int maxn = 2e5 + 10;

int n, k;
ll a[maxn], ans, m = 1e18;
deque<pii>d;

void correct(int l, int r, ll &sum){
	while(!d.empty() && d.front().first < l) d.pop_front();

	debug("sum = %lld\n",sum);

	while(!d.empty() && sum >= 0){
		pii p = d.back();
		d.pop_back();
		int pos = p.first;
		ll val = p.second;
		ll bonus = val - m;
		debug("(%d,%lld)\n",pos,val);
		if(sum - bonus >= 0){
			debug("first\n");
			sum -= bonus;
			a[pos] -= bonus;
			ans += bonus;
			assert(a[pos] >= m);
		} else {
			debug("second\n");
			bonus = sum + 1;
			debug("bouns = %lld\n",bonus);
			a[pos] -= bonus;
			assert(a[pos] >= m);
			sum -= bonus;
			ans += bonus;
			d.pb(pii(pos,a[pos]));
			assert(sum < 0);
		}	
	}
}

void solve(){
	ll sum = 0;
	for(int i = 1; i <= k; ++i){
		if(a[i] != m) d.pb(pii(i,a[i])); 
		sum += a[i];
	}

	correct(1,k,sum);
	for(int i = k + 1; i <= n; ++i){
		sum += a[i];
		sum -= a[i-k];
		if(a[i] != m) d.pb(pii(i,a[i]));
		correct(i-k+1,i,sum);
	}
}

int main(){
	cin.sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		m = min(m,a[i]);
	}
	debug("m = %lld\n",m);
	solve();
	cout << ans << '\n';
	for(int i = 1; i <= n; ++i)
		cout << a[i] << " ";
	cout << '\n';
	return 0;
}
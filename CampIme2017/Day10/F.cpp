#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 10;

int n, k;
ll a[maxn];

ll dp[maxn];
ll pre[maxn], PRE[maxn];

ll solve(){
	for(int i = 1; i <= n; ++i)
		pre[i] = pre[i-1] + a[i];

	for(int i = 1; i <= k; ++i)
		PRE[i] = max(PRE[i-1],pre[i]);

	for(int i = k + 1; i <= n; ++i)
		PRE[i] = max(PRE[i-1],pre[i]-pre[i-k]);

	ll ans = 0;
	for(int i = 1; i <= k; ++i)
		ans = max(ans,PRE[i]);

	for(int i = k + 1; i <= n; ++i)
		ans = max(ans,PRE[i-k] + pre[i] - pre[i-k]);

	return ans;
}

int main(){
	cin.sync_with_stdio(false);
	
	cin >> n >> k;

	for(int i = 1; i <= n; ++i) cin >> a[i];
	cout << solve() << '\n';

	return 0;
}
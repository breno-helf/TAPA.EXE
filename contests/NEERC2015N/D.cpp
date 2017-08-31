#include<bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

vector<ll> resp;
ll n;

void solve(ll k) {
    if (k == 0 || k == 1) return;
    
    //printf("--> %lld\n", k);
    
    ll fac = 0;
    while (k % 2 == 0) {
	k /= 2;
	fac++;
    }


    if (k == 1) {
	if (fac > 0) resp.pb((1LL<<fac));
	return;
    }

    ll num = 1;
    while (num * 3 <= k) {
	num *= 3;
    }

    solve(k - num);

    resp.pb(num);
    for (int i = 0; i < (int)resp.size(); i++) {
	resp[i] = ((ll)resp[i]<<fac);
    }

}
int main() {
    freopen("distribution.in", "r", stdin);
    freopen("distribution.out", "w", stdout);

    int t;
    scanf("%d", &t);
    while (t--) {
	resp.clear();
	scanf("%lld", &n);

	
	
	if (n != 1) solve(n);
	else resp.pb(1);
	
	printf("%d\n", (int)resp.size());

	for (ll x : resp)
	    printf("%lld ", x);
	printf("\n");
    }
}

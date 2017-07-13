#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i = a; i <= b; ++i)

typedef long long ll;

map<ll,ll>dp;

ll f(ll n){
	if(n == 1) return 0;
	if(dp.find(n) != dp.end()) return dp[n];
	ll L = sqrt(n);
	return dp[n] = n + f(L) + f(n - L);
}

int main(){
	ll n;
	scanf("%lld",&n);
	printf("%lld\n",f(n));
	return 0;

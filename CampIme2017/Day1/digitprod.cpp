#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define pb push_back

typedef long long ll;
typedef pair<int, ll> pii;

const ll mod = 1e9 + 7;
const int len = 100;

int t;
ll n;

map<pii,ll>dp;
map<pii,bool>memo;

ll f(int i, ll val){
	if(i > len) return val == 1;
	pii p = pii(i,val);
	if(memo.find(p) != memo.end()) return dp[p];
	memo[p] = true;
	ll cur = 0;
	if(val == 1){
		dp[p] = 1;
		return 1;
	}
	FOR(d,1,9)
		if(val % d == 0)
			cur = (cur + f(i+1,val/d)) % mod;
	dp[p] = cur;
	
	return cur;
}

ll DP[2][2][len + 10];

ll F(int a, int b, int i){
	if(DP[a][b][i] == -1){
		if(i > len){
			if(a && b) return 1;
			return 0;
		}
		DP[a][b][i] = 0;
		int start;
		if(a) start = 0;
		else start = 1;
		FOR(d,0,9) 
			DP[a][b][i] = (DP[a][b][i] + F(max(a,(int)(d!=0)),max(b,(int)(d==0 && a)),i+1)) % mod;
	}
	return DP[a][b][i];
}

int main (){
	memset(DP,-1,sizeof(DP));
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		if(!n) printf("%lld\n",(F(0,0,1) + 1) % mod);
		else{
			ll sum = 0;
			FOR(i,1,100)
				sum = (sum + f(i,n)) % mod;
			printf("%lld\n",sum);
		}
	}
	return 0;
}

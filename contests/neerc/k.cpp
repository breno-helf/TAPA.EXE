#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define REP(i,a,b) for(int i = a; i >= b; --i)
#define debug(args...) fprintf(stderr,args);

typedef pair<int,int>pii;
const int maxn = 3e5 + 10;

int n, a[maxn];
vector<pii>ans;

int r[maxn], l[maxn];

int dp[maxn];
pii pointer[maxn];

int f(int i){
	if(dp[i] == -1){
		if(i > n) return dp[i] = 0;
		dp[i] = 1e7;
		if(dp[i] > 1 + f(l[i] + 1)){
			dp[i] = 1 + f(l[i] + 1);
			pointer[i] = pii(l[i]+1,0);
		}
		if(dp[i] > 1 + f(r[i] + 1)){
			dp[i] = 1 + f(r[i] + 1);
			pointer[i] = pii(r[i]+1,1);
		}
	}
	return dp[i];
}

void compute(){
	int i = 1;
	while(i <= n){
		int p = pointer[i].first;
		int type = pointer[i].second;
		if(!type) ans.pb(pii(i,p-1));
		else ans.pb(pii(p-1,i));
		i = p;
	}
}

void solve(){	
	queue<int>Q;
	FOR(i,1,n){
		while(!Q.empty() && i - Q.front() + 1 > a[i]){
			l[Q.front()] = i - 1;
			Q.pop();
		}
		Q.push(i);
	}

	while(!Q.empty()){
		l[Q.front()] = n;
		Q.pop();
	}

	REP(i,n,1){
		while(!Q.empty() && Q.front() - i + 1 > a[i]) Q.pop();
		if(Q.empty()) r[i] = i;
		else r[i] = Q.front();
		Q.push(i);
	}

	memset(dp,-1,sizeof(dp));
	f(1);
	compute();
}

int main(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",&a[i]);
	solve();
	printf("%d\n",(int)ans.size());
	for(auto i: ans) printf("%d %d\n",i.first,i.second);
	return 0;
}
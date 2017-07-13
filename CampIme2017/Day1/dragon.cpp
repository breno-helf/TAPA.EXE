#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define debug(args...) fprintf(stderr,args)
#define FOR(i,a,b) for(int i = a; i <= b; ++i)

typedef long long ll;
typedef pair<ll,ll>pii;
const int maxn = 3e2 + 10;
const ll INF = 1e18;

int n, m, d;

struct dsu{
	int par[maxn], sz[maxn];
	void init(){
		FOR(i,1,n){
			par[i] = i;
			sz[i] = 1;
		}
	}
	int root(int v){
		if(par[v] == v) return v;
		return root(par[v]);
	}
	void merge(int x, int y){
		x = root(x);
		y = root(y);
		if(x == y) return;
		if(sz[y] > sz[x]) swap(x,y);
		sz[x] += sz[y];
		par[y] = x;
	}
} T;

vector<pii>D[maxn];
ll ans;

bool cmp(pii a, pii b){
	return (a.first < b.first) || (a.first == b.first && a.second < b.second);
}

ll solve(int id){
	if(D[id].empty()) return 0;
	sort(D[id].begin(),D[id].end(),cmp);
	ll soma = 0;
	for(auto i: D[id])
		soma += i.second;
	ll ans = soma;
	ll gmax = D[id].back().first;
	if(!gmax){
		ans = min(ans,D[id].back().second);
		return ans;
	}
	ans = min(ans,gmax+1);
	ll sum = 0;
	while(!D[id].empty()){
		if(!gmax){
			ans = min(ans,max(sum,D[id].back().second));
			return ans;
		}
		while(!D[id].empty() && gmax == D[id].back().first){
			sum += D[id].back().second;
			D[id].pop_back();
		}
		if(!D[id].empty()) gmax = D[id].back().first;
		ans = min(ans,max(gmax+1,sum));
	}
	return ans;
}

int main(){
	scanf("%d%d%d",&n,&m,&d);
	T.init();
	FOR(i,1,m){
		int a, b;
		scanf("%d%d",&a,&b);
		++a;
		++b;
		T.merge(a,b);
	}
	FOR(i,1,d){
		int node;
		ll s, g;
		scanf("%d%lld%lld",&node,&s,&g);
		++node;
		node = T.root(node);
		D[node].pb(pii(g,s));
	}
	FOR(i,1,n) ans += solve(i);
	printf("%lld\n",ans);
	return 0;
}
#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
const int maxn = 1e5 + 10;

int n, m, q, b[maxn];
bool on[maxn];
vector<int>adj[maxn];

struct line{
	int x, type, id;
	line(int x, int type, int id) : x(x), type(type), id(id) {}
};
bool operator<(line a, line b){
	return (a.x < b.x) || (a.x == b.x && a.type < b.type);
}
vector<line>vec;

struct query{
	int node, d, pos;
	query(int node, int d, int pos) : node(node), d(d), pos(pos) {}
};
vector<query>Q;

struct dsu{
	int par[maxn];
	int sz[maxn];
	vector<int>dis;
	void init(){
		FOR(i,1,n){
			par[i] = i;
			sz[i] = 1;
			dis.pb(b[i]);
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
}

int ans[maxn];

void solve(){
	sort(vec.begin(),vec.end());
	for(int i = 0; i < vec.size(); ++i){
		int type = vec[i].type;
		int id = vec[i].id;

	}
}

int main(){
	scanf("%d%d%d",&n,&m,&q);
	FOR(i,1,n) scanf("%d",&b[i]), vec.pb(line(b[i],0,-1));
	FOR(i,1,m){
		int u, v;
		scanf("%d%d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	FOR(i,0,q-1){
		int node, d, pos;
		scanf("%d%d%d",&node,&d,&pos);
		--pos;
		Q.pb(query(node,d,pos));
		vec.pb(line(d,1,i));

	}
	solve();
	FOR(i,0,q-1) printf("%d\n",ans[i]);
	return 0;
}
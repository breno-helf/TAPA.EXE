#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define FOR(i,a,b) for(int i = a; i <= b; ++i)

typedef long long ll;
typedef pair<ll,int>pii;
const int maxn = 1e4 + 10;

int n, m;
vector<pii>adj[maxn];

ll dis[2][maxn];
bool mrk[2][maxn];

struct node{
	ll dis;
	int id, v;
	node(ll dis, int id, int v) : dis(dis), id(id), v(v) {}
};

bool operator<(node a, node b){
	return a.dis < b.dis;
}

ll dijkstra(){	
	memset(dis,-1,sizeof(dis));
	dis[0][1] = 0;
	multiset<node>Set;
	Set.insert(node(dis[0][1],0,1));
	while(!Set.empty()){
		int v = Set.begin()->v;
		int id = Set.begin()->id;
		Set.erase(Set.begin());
		if(mrk[id][v]) continue;
		mrk[id][v] = true;
		for(auto i: adj[v]){
			int c = i.first;
			int u = i.second;
			if(!mrk[id^1][u] && (dis[id^1][u] == -1 || dis[id^1][u] > dis[id][v] + c)){
				dis[id^1][u] = dis[id][v] + c;
				Set.insert(node(dis[id^1][u],id^1,u));
			}
		}
	}

	return dis[0][n];
}

int main(){
	scanf("%d%d",&n,&m);
	FOR(i,1,m){
		int a, b, c;
		scanf("%d%d%d",&a,&b,&c);
		adj[a].pb(pii(c,b));
		adj[b].pb(pii(c,a));
	}
	printf("%lld\n",dijkstra());
	return 0;
}
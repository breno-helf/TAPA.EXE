#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int,int>pii;

#define pb push_back
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define debug(args...) //fprintf(stderr,args);

int n, a, b;
vector<pii>sock[3],cur[3];
vector<pii>ans;
ll resp;

struct edge{
	int t, w, id;
	edge(int t, int w, int id) : t(t), w(w), id(id) {}
};

bool operator<(edge a, edge b){
	return a.w < b.w;
}

priority_queue<edge>Q;

void solve(){
	FOR(i,0,2){
		sort(sock[i].begin(),sock[i].end());
		reverse(sock[i].begin(),sock[i].end());
	}

	int A = 0, B = 0;

	while(!sock[0].empty() && A < a){
		int w = sock[0].back().first;
		int id = sock[0].back().second;
		Q.push(edge(0,w,id));
		++A;
		debug("add(%d,%d)\n",w,id)
		sock[0].pop_back();
	}

	while(!sock[1].empty() && B < b){
		int w = sock[1].back().first;
		int id = sock[1].back().second;
		Q.push(edge(1,w,id));
		++B;
		debug("ADD(%d,%d)\n",w,id)
		sock[1].pop_back();
	}

	debug("%d %d\n",A,B);

	int c = 0;
	vector<pii>vec;

	while(Q.size() + c < a + b && !sock[2].empty()){
		int w = sock[2].back().first;
		int id = sock[2].back().second;
		sock[2].pop_back();
		++c;
		vec.pb(pii(w,id));	
	}

	while(!Q.empty() && !sock[2].empty() && sock[2].back().first < Q.top().w){
		int w = sock[2].back().first;
		int t = sock[2].back().second;
		Q.pop();
		sock[2].pop_back();
		vec.pb(pii(w,t));
		debug("entra(%d,%d)\n",w,t);
	}

	for(auto i: vec) Q.push(edge(2,i.first,i.second));

	while(!Q.empty()){
		int t = Q.top().t;
		int w = Q.top().w;
		int id = Q.top().id;
		Q.pop();
		cur[t].pb(pii(w,id));
	}		

	A = 0, B = 0;
	for(auto i: cur[0]) ans.pb(pii(i.second,++A)), resp += i.first;
	for(auto i: cur[1]) ans.pb(pii(i.second,a+(++B))), resp += i.first;
	for(auto i: cur[2]){
		resp += i.first;
		if(A < a) ans.pb(pii(i.second,++A));
		else ans.pb(pii(i.second,a+(++B)));
	}
}

int main(){
	scanf("%d%d%d",&n,&a,&b);
	FOR(i,1,n){
		int t, w;
		scanf("%d%d",&t,&w);
		sock[t-1].pb(pii(w,i));
	}
	solve();
	printf("%d %lld\n",(int)ans.size(),resp);
	for(auto i: ans) printf("%d %d\n",i.first,i.second);
	return 0;
}
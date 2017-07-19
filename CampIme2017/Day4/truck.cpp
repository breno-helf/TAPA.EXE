#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define FOR(i,a,b) for(int i = a; i <= b; ++i)

typedef double ld;
const int maxn = 1e2 + 10;
const ld INF = 1e18;
const ld eps = 1e-6;
int n, m;

bool equal (ld a, ld b) {
    return (abs(a - b) <= eps);
}

struct edge{
	int a, b;
	ld c;
	edge(int a, int b, ld c) : a(a), b(b), c(c) {}
};
vector<edge>e,E;

void build(ld x){
	E.clear();
	for(auto i: e) E.pb(edge(i.a,i.b,i.c-x));
}

ld dis[maxn], DIS[maxn];

bool ok(ld x){
	build(x);
	for (auto ed : E) {
	    cout << ed.a << ' ' << ed.b << ' ' << ed.c << '\n';
	}
	FOR(i,1,n) dis[i] = 1e10;
	
	FOR(i,1,n + 10)
		for(auto j: E){
			int u = j.a;
			int v = j.b;
			ld c = j.c;
			dis[v] = min(dis[v],dis[u]+c);
		}

	FOR(i,1,n) DIS[i] = dis[i];

	for(auto j: E){
			int u = j.a;
			int v = j.b;
			ld c = j.c;
			dis[v] = min(dis[v],dis[u]+c);
		}

	FOR(i,1,n) {
	    cout << dis[i] << " -- " << DIS[i] << '\n';
	}
	
	FOR(i,1,n) if(dis[i] + eps< DIS[i]) return true; //cicle found
	return false;
}

ld solve(){
	ld ini = 0, fim = 1e10;

	cout << ok(3.1) << '\n';
	
	// FOR(i,1,120){
	//     ld mid = (ini+fim)/2.0;
	//     cout << mid << '\n';
	//     cout << ok(mid) << '\n';
	// 	if(ok(mid)) fim = mid;
	// 	else ini = mid;
	// }
	return ini;
}

int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	FOR(i,1,m){
		int a, b;
		ld c;
		cin >> a >> b >> c;
		e.pb(edge(a,b,c));
	}
	cout << fixed << setprecision(15) << solve() << '\n';
	return 0;
}

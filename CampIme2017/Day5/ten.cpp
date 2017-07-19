#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
const int maxn  = 1e5 + 10;

struct line{
	ll x;
	int type, id;
	line(ll x, int type, int id) : x(x), type(type), id(id) {}
};
bool operator<(line a, line b){
	return (a.x < b.x) || (a.x == b.x && a.type < b.type);
}
vector<line>l;

int ans[maxn];

int n;

void solve(){
	int resp = 0;
	sort(l.begin(),l.end());
	for(int i = 0; i < l.size(); ++i){
		int type = l[i].type;
		int id = l[i].id;
		if(!type) ++resp;
		if(type == 2) --resp;
		if(type == 1) ans[id] = resp;
	}
}

int main(){
	cin >> n;
	for(int i = 0; i < n; ++i){
		ll x;
		cin >> x;
		ll L = (9*x+9)/10;
		ll R = (11*x)/10;
		l.push_back(line(L,0,-1));
		l.push_back(line(R,2,-1));
	}	
	int q;
	cin >> q;
	for(int i = 1; i <= q; ++i){
		ll x;
		cin >> x;
		l.push_back(line(x,1,i));
	}
	solve();
	for(int i = 1; i <= q; ++i) cout << ans[i] << '\n';
	return 0;
}
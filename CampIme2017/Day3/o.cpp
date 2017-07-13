#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define FOR(i,a,b) for(int i = a; i <= b; ++i)

const int maxd = 30;

struct pii{
	int l, r, id;
	pii(int l, int r, int id) : l(l), r(r), id(id) {}
};

bool operator<(pii a, pii b){
	return (a.l < b.l);
}

int n, d;
vector<pii> days[maxd];

int X, Y;

void solve(int idx){
	X = -1, Y = -1;
	if(days[idx].size() < 2	) return;
	int rmin = INT_MAX;
	sort(days[idx].begin(),days[idx].end());
	FOR(i,0,days[idx].size() - 1){
		int l = days[idx][i].l;
		int r = days[idx][i].r;
		int id = days[idx][i].id;
		if(l > rmin){
			Y = id;
			return;
		}
		if(rmin > r){
			rmin = r;
			X = id;
		}
	}
}

int main(){
	scanf("%d%d",&n,&d);
	FOR(i,1,n){
		int l, r, day;
		scanf("%d%d%d",&l,&r,&day);
		days[day].pb(pii(l,r,i));
	}
	FOR(i,1,d){
		solve(i);
		if(Y == -1) printf("NIE\n");
		else printf("ANO %d %d\n",X,Y);
	}
	return 0;
}
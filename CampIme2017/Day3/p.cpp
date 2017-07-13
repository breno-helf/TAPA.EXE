#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define debug(args...) fprintf(stderr,args)

typedef pair<int,int>pii;

int n;

vector<int>vec;

int solve(){
	set<pii>on;
	set<pii>::iterator l, r;
	vector<pii>a;
	int sz = (int)vec.size();
	FOR(i,1,sz-2)
		a.pb(pii(vec[i],i));
	sort(a.begin(),a.end());
	on.insert(pii(0,0));
	on.insert(pii(sz-1,0));
	int ans = 0;
	FOR(i,0,a.size()-1){
		int j = i;
		while(j < sz-1 && a[i].first == a[j].first){
			int height = a[i].first;
			int pos = a[j].second;
			on.insert(pii(pos,height));
			l = on.find(pii(pos,height));
			r = l;
			--l;
			++r;
			if(l->second < height && height > r->second) ++ ans; 
			++j;
		}
		i = j - 1;
	}
	return ans;
}

int main(){
	scanf("%d",&n);
	vec.pb(0);
	FOR(i,1,n){
		int w, h;
		scanf("%d%d",&w,&h);
		if(vec.empty() || vec.back() != h) vec.pb(h);
	}
	vec.pb(0);
	printf("%d\n",min(n,solve()));
	return 0;
}
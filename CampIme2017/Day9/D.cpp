#include "bits/stdc++.h"
using namespace std;

#define debug(args...) fprintf(stderr,args)

typedef long long ll;

const int maxn = 5e4 + 10;
const int block = 300;

int n, q, a[maxn];

vector<int>vec[maxn];

ll dp[block][maxn];

ll query(int x, int fim){
	int p = vec[x].size();
	int q = lower_bound(vec[x].begin(),vec[x].end(),-fim) - vec[x].begin();
	return p - q;
}

inline ll f(int x, int y){
	ll ans = 0;
	
	if(!y || !x) return 0LL;

	int b = (x - 1) / block + 1;
	int pointer = (b - 1) * block + 1;

	++pointer;
	ans += dp[b][y];
	
	while(pointer <= x){
		//debug("pointer = %d\n",pointer);
		int val = a[pointer];
		ans += query(val,y);
		++pointer;		
	}
	//debug("f(%d,%d) = %lld\n",x,y,ans);
	return ans;
}

void precompute(){
	for(int b = 1; b <= block; ++b){
		int r = (b-1)*block+1;
		if(r > n) break;
		for(int i = 1; i <= n; ++i)
			dp[b][i] = dp[b][i-1] + query(a[i],r);
	}
}

int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		vec[a[i]].push_back(-i);
	}

	for(int i = 1; i <= n; ++i) 
		reverse(vec[i].begin(),vec[i].end());

	precompute();

	cin >> q;
	while(q--){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << f(b,d) + f(a-1,c-1) - f(a-1,d) - f(b,c-1) << '\n';
	}
	return 0;

}
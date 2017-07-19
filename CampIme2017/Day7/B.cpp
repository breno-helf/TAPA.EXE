#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i = a; i <= b; ++i)
const int maxn = 1e6 + 10;

int t;

int n, m;
bool mrk[maxn];

int out[maxn];

int main(){
	cin.sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> n >> m;
		FOR(i,1,n) mrk[i] = false, out[i] = 0;
		FOR(i,1,m){
			int x, y;
			cin >> x >> y;
			if(x > y) swap(x,y);
			mrk[y] = true;
			++out[x];
		}
		if(!mrk[n]) cout << "2 " << n << '\n';
		else{
			bool ok = false;
			FOR(i,1,n)
				if(!mrk[i] && n - i == out[i]){
					cout << "2 " << i << '\n';
					ok = true;
					break;
				}
			if(ok) continue;
			cout << "1\n";
		}
	}
	return 0;
}
#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
typedef pair<int,int>pii;
const int maxn = 2000 + 10;

int n;
int g[maxn][maxn];

vector<int>adj[maxn];

int c;

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
	vector<pii>e;
	scanf("%d", &n);
	
	FOR(i,1,n){
	    FOR(j,1,n) cin >> g[i][j];
	    e.pb(pii(min(i,g[i][2]),max(i,g[i][2])));
	}
	
	sort(e.begin(),e.end());
	e.erase(unique(e.begin(),e.end(),e.end());


		X
    }
	    
    return 0;
}

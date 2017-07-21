#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define debug(args...) fprintf(stderr,args)

typedef long long ll;
const int maxn = 55;


int q, n;
int f[maxn][maxn][maxn];
int a[maxn * maxn * maxn];

int dp[4][maxn][maxn][maxn][maxn];
int linha[3][maxn][maxn][maxn][maxn];

int ans[maxn];

int h(int id, int x, int y, int z, int l){
	if(linha[id][x][y][z][l] == -1){
		if(l == 1) return linha[id][x][y][z][l] = f[x][y][z];
		if(id == 0) linha[id][x][y][z][l] = max(f[x+l-1][y][z],h(0,x,y,z,l-1));
		if(id == 1) linha[id][x][y][z][l] = max(f[x][y][z+l-1],h(1,x,y,z,l-1));
		if(id == 2) linha[id][x][y][z][l] = max(f[x][y+l-1][z],h(2,x,y,z,l-1));
	}
	return linha[id][x][y][z][l];
}

int g(int id, int x, int y, int z, int l){
	if(dp[id][x][y][z][l] == -1){
		if(l == 1) return dp[id][x][y][z][l] = f[x][y][z];
		if(id == 0) dp[id][x][y][z][l] = max(g(0,x,y,z,l-1),max(g(1,x,y+l-1,z,l),max(g(2,x+l-1,y,z,l),g(3,x,y,z+l-1,l))));
		if(id == 1) dp[id][x][y][z][l] = max(g(1,x,y,z,l-1),max(h(0,x,y,z+l-1,l),h(1,x+l-1,y,z,l)));
		if(id == 2) dp[id][x][y][z][l] = max(g(2,x,y,z,l-1),max(h(1,x,y+l-1,z,l),h(2,x,y,z+l-1,l)));
		if(id == 3) dp[id][x][y][z][l] = max(g(3,x,y,z,l-1),max(h(2,x+l-1,y,z,l),h(0,x,y+l-1,z,l)));
	}
	return dp[id][x][y][z][l];
}

inline void solve(){
	memset(dp,-1,sizeof(dp));
	memset(linha,-1,sizeof(linha));

	FOR(i,1,n) ans[i] = 0;

	FOR(x,1,n)
		FOR(y,1,n)
			FOR(z,1,n)
				for(int l = 1; x+l-1 <= n && y+l-1 <= n && z+l-1 <= n; ++l)
					if(g(0,x,y,z,l) == l)
						++ans[l];
}

int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> q;

	while(q--){
		cin >> n;

		FOR(i,1,n*n*n) cin >> a[i];
		
		FOR(x,1,n) FOR(y,1,n) FOR(z,1,n) f[x][y][z] = a[(x-1)*n*n + (y-1)*n + z];

		solve();
		FOR(i,1,n) cout << ans[i] << " ";
		cout << '\n';
	}

	return 0;
}
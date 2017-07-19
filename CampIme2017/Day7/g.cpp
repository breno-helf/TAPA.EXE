#include "bits/stdc++.h"
using namespace std;

#define debug(args...) //fprintf(stderr,args)

const int maxn = 55;
int t, n, m, k;
char s[maxn][maxn];
int g[maxn][maxn];

int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--){
		cin >> n >> m >> k;

		int soma = 0;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j){
				cin >> s[i][j];
				if(s[i][j] == '.') g[i][j] = 0;
				else g[i][j] = 1, ++soma;
			}

		int ans = soma;
		while(k--){

			int maior = INT_MIN;
			int x = -1;

			for(int i = 1; i <= n; ++i){

				int on = 0;
				int off = 0;

				for(int j = 1; j <= m; ++j)
					if(g[i][j]) ++on;
					else ++off;

				debug("%d %d\n",on,off);

				if(-on+off > maior){
					maior = -on+off;
					x = i;
				}
			}

			debug("maior = %d\n",maior);
			ans += maior;

			if(x != -1)
				for(int j = 1; j <= m; ++j)
					g[x][j] ^= 1;
		}

		cout << ans << '\n';
	}
	return 0;
}
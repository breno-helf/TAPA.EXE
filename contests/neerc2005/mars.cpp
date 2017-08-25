#include "bits/stdc++.h"
using namespace std;

typedef pair <int, int> pii;

const int maxn = 6e2 + 10;
const int INF = 1e8;

int n, k, p, b[maxn];

vector <pii> gum[maxn];
vector <int> w[maxn];

int dp[maxn][maxn];
int go[maxn][maxn];

vector <int> ans;
int resp;
int G;

void solve() {
	for(int i = 1; i <= k; ++i) {
		sort(gum[i].begin(), gum[i].end());
		
		if(gum[i].empty())
			continue;
			
		int sum = b[i];
		for(int j = 0; j < gum[i].size(); ++j) {
			int W = gum[i][j].first;
			sum += W;
			w[i].push_back(sum);
		}
	}
	
	for(int r = 1; r <= n; ++r)
		dp[0][r] = INF;
	
	for(int g = 1; g <= k; ++g) {
		dp[g][0] = dp[g - 1][0];
		go[g][0] = -1;
		
		for(int r = 1; r <= n; ++r) {
			dp[g][r] = dp[g - 1][r];
			go[g][r] = -1;
		}
		
		for(int i = 0; i < w[g].size(); ++i) {
			int W = w[g][i];
			int sz = i + 1;
			
			for(int r = sz; r <= n; ++r) {
				if(dp[g][r] > dp[g - 1][r - sz] + W) {
					dp[g][r] = dp[g - 1][r - sz] + W;
					go[g][r] = sz - 1;
				}
				
				if(dp[g][r] <= p) 
					resp = max(resp, r); 
			}
		}
	}
}

void build() {
	for(int g = k; g >= 1; --g) {
		for(int i = 0; i <= go[g][resp]; ++i) {
			int id = gum[g][i].second;
			ans.push_back(id);
		}
		
		resp -= (go[g][resp] + 1);
	}
}

int main() {
	scanf("%d %d %d", &n, &k, &p);
	
	for(int i = 1; i <= k; ++i)
		scanf("%d", &b[i]);
	
	for(int i = 1; i <= n; ++i) {
		int a, c;
		scanf("%d %d", &a, &c);
		
		gum[c].push_back( {a, i} );
	}
	
	solve();
	build();
	
	printf("%d\n", ans.size());
	
	for(int i = 0; i < ans.size(); ++i)
		printf("%d ", ans[i]);
	
	return 0;
}

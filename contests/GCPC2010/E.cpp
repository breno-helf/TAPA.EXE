#include "bits/stdc++.h"
using namespace std;

#define debug(args...) fprintf(stderr, args)

const int MAXN = 1e4 + 10;
const int MAXM = 1e2 + 10;
const int MAXA = 27;

int t;

int n, m, k;
char s[MAXN];

int idx;
int adj[MAXN * MAXM][MAXA];
int c[MAXN * MAXM]; // children
int par[MAXN * MAXM];
char val[MAXN * MAXM];
int height[MAXN * MAXM];

char ans[MAXM];
int len;

inline void solve() {
	idx = 0;
	c[0] = 0;
	
	for(int i = 1; i <= k; ++i)
		adj[0][i] = 0;
	
	for(int i = 0; i < n; ++i) {
		int node = 0;
		
		for(int cnt = m, j = i; cnt > 0 && j < n; cnt--, ++j) {
			if(s[j] - 'a' + 1 > k)
				break;
				
			int dir = s[j] - 'a' + 1;
		
			if(!adj[node][dir]) {
				++c[node];
				adj[node][dir] = ++idx;
				height[idx] = height[node] + 1;
				
				c[idx] = 0;
				for(int it = 1; it <= k; ++it)
					adj[idx][it] = 0;
				
				par[idx] = node; 
				val[idx] = s[j];
			}
		
			node = adj[node][dir];
		} 
	}
	
	for(int i = 0; i <= idx; ++i)
		if(c[i] < k && height[i] != m) {
			int node = i;
			
			len = height[i] + 1;
			
			int pos = height[i] - 1;
			
			while(node) {
				ans[pos] = val[node];
				node = par[node];
				--pos;
			}
		
			for(int c = 1; c <= k; ++c) 
				if(!adj[i][c]) {
					ans[len - 1] = c - 1 + 'a';
					break;
				}
			
			break;
		}
	
}

int main() {
	scanf("%d", &t);
	
	while(t--) {
		scanf(" %d %d %d %s", &n, &m, &k, s);
		solve();
		for(int i = 0; i < len; ++i)
			printf("%c", ans[i]);
		printf("\n");
	}
	
	return 0;
}

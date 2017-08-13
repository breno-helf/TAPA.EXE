#include "bits/stdc++.h"
using namespace std;

#define debug(args...) // fprintf(stderr, args)

const int maxn = 40 + 10;

int n, m;
string s[maxn];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int comps;

bool mrk[maxn][maxn];

void dfs(int i, int j) {
	mrk[i][j] = true;

	for(int k = 0; k < 4; ++k) {
		int x = i + dx[k];
		int y = j + dy[k];

		if(x < 0 || y < 0 || x >= n || y >= m || mrk[x][y] || s[x][y] != 'L')
			continue;

		dfs(x, y);
	}
}

void FILL() {
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(s[i][j] == 'L' && !mrk[i][j]) {
				dfs(i, j);
				++comps;
			}

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j) 
			if(s[i][j] == 'L') {
				for(int k = 0; k < 4; ++k) {
					int x = i + dx[k];
					int y = j + dy[k];

					if(x < 0 || y < 0 || x >= n || y >= m)
						continue;

					if(s[x][y] == 'C') 
						s[x][y] = 'W';
				}
			}
}

vector <int> adj[maxn * maxn];
bool black[maxn][maxn];

int match[maxn * maxn];
bool used[maxn * maxn];

bool dfs(int v) {
	for(auto u: adj[v]) 
		if(!used[u]) {
			used[u] = true;

			if(match[u] == -1 || dfs(match[u])) {
				match[u] = v;
				return true;
			}
		}

	return false;
}

int matching() {
	memset(match, -1, sizeof(match));

	int ans = 0;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(black[i][j] && s[i][j] == 'C') {
				memset(used, false, sizeof(used));

				if(dfs(i * m + j)) 
					++ans;
			}

	return ans;
}

int solve() {
	FILL();

	int par = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j)
			if(j % 2 == par)
				black[i][j] = 1;
		par ^= 1;
	}

	int nodes = 0;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(s[i][j] == 'C') 
				++nodes;

	debug("nodes = %d\n", nodes);

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j) 
			if(s[i][j] == 'C' && black[i][j]) {
				int v = i * m + j;
				for(int k = 0; k < 4; ++k) {
					int x = i + dx[k];
					int y = j + dy[k];

					if(x < 0 || y < 0 || x >= n || y >= m || s[x][y] != 'C')
						continue;

					int u = x * m + y;

					debug("(%d,%d) -> (%d,%d)\n", i, j, x, y);
					adj[v].push_back(u);
				}	
			}

	debug("match = %d\n", matching());

	comps += nodes - matching();

	return comps;
}

int main() {
	cin >> n >> m;

	for(int i = 0; i < n; ++i)
		cin >> s[i];

	cout << solve() << '\n';

	return 0;

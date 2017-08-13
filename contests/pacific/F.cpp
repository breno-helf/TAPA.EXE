#include "bits/stdc++.h"
using namespace std;

const int maxn = 1e3 + 10;

int N, r, n;

int X[maxn], Y[maxn];

vector <int> stk;
vector <int> adj[maxn << 1];
bool on[maxn << 1];
int low[maxn << 1], h[maxn << 1], id;
bool mrk[maxn << 1];
int comp[maxn << 1], cnt;

void build() {
	for(int i = 1; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j) {
			if(X[i] == X[j]) {
				if(abs(Y[i] - Y[j]) <= r) {
					adj[i + n].push_back(j);
					adj[j + n].push_back(i);
				}
			}

			if(Y[i] == Y[j]) {
				if(abs(X[i] - X[j]) <= r) {
					adj[i].push_back(j + n);
					adj[j].push_back(i + n);
				}
			}
		}
}

void dfs(int v) {
	low[v] = h[v] = ++id;
	on[v] = true;
	stk.push_back(v);
	mrk[v] = true;

	for(auto u: adj[v]) 
		if(!mrk[u]) {
			dfs(u);
			low[v] = min(low[v], low[u]);
		}
		else 
			if(on[u])
				low[v] = min(low[v], h[u]);

	if(h[v] == low[v]) {
		++cnt;
		while(!stk.empty()) {
			int u = stk.back();
			stk.pop_back();
			comp[u] = cnt; 
			on[v] = false;
			
			if(u == v)
				break;
		}
	}
}

bool solve() {
	build();
	for(int i = 1; i <= n + n; ++i)
		if(!mrk[i]) 
			dfs(i);
	
	for(int i = 1; i <= n; ++i)
		if(comp[i] == comp[i + n])
			return false;

	return true;
}

int main() {
	cin >> N >> r >> n;

	for(int i = 1; i <= n; ++i) 
		cin >> X[i] >> Y[i];

	if(solve())
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}

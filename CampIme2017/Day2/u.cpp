#include "bits/stdc++.h"
using namespace std;

#define pb push_back
const int maxn = 1e5 + 10;

int n;
string s;

vector<int>adj[maxn];
int deg[maxn];

int ans[maxn], cnt;

bool mrk[maxn];
queue<int>q;

void solve(){
	for(int i = 1; i <= n; ++i)
		if(!deg[i]){
			q.push(i);
			mrk[i] = true;
		}
	while(!q.empty()){
		int v = q.front();
		q.pop();
		ans[v] = ++cnt;
		for(auto u: adj[v])
			if(!mrk[u]){
				--deg[u];
				if(!deg[u]){
					mrk[u] = true;
					q.push(u);
				}
			}
	}
}

int main(){
	cin >> s;
	n = (int)s.size() + 1;
	for(int i = 0; i < s.size(); ++i)
		if(s[i] == '<')
			adj[i+1].pb(i+2), ++deg[i+2];
		else adj[i+2].pb(i+1), ++deg[i+1];
	solve();
	for(int i = 1; i <= n; ++i) cout << ans[i] << " ";
	return 0;
}
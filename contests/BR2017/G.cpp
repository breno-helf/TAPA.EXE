#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
const int maxn = 3e5 + 10;
const ll mod = 1e9 + 7;

int n;

int id;
vector<int> adj[maxn];

ll ways[2][maxn];
int type[maxn];

ll incorrect[maxn];

void dfs(int v) {
  for(int i = 0; i < adj[v].size(); ++i) {
    int u = adj[v][i];
    dfs(u);
  }

  if(adj[v].empty()) {
    // leaf
    ways[0][v] = ways[1][v] = 1;
  }
  else {
    int l = adj[v][0];
    int r = adj[v][1];

    if(type[v] == -1) {
      ways[0][v] = (ways[1][l] * ways[1][r]) % mod; 
      
      for(int i = 0; i <= 1; ++i)
	for(int j = 0; j <= 1; ++j)
	  if(!i || !j)
	    ways[1][v] = (ways[1][v] + ways[i][l] * ways[j][r]) % mod;
    }
    else
      if(!type[v]) {
	 ways[0][v] = (ways[1][l] * ways[1][r]) % mod;
	 ways[1][v] = ways[0][v];
      }
      else {
	for(int i = 0; i <= 1; ++i)
	  for(int j = 0; j <= 1; ++j)
	    if(!i || !j)
	      ways[1][v] = (ways[1][v] + ways[i][l] * ways[j][r]) % mod;

	ways[0][v] = ways[1][v];
      }

    if(!type[v]) {
      for(int i = 0; i <= 1; ++i)
	for(int j = 0; j <= 1; ++j)
	  if(!i || !j)
	    incorrect[v] = (incorrect[v] + ways[i][l] * ways[j][r]) % mod; 
    }
    else
      if(type[v] == 1) {
	incorrect[v] = (incorrect[v] + ways[1][l] * ways[1][r]) % mod;
      }
      else {
	incorrect[v] = (incorrect[v] + ways[1][l] * ways[1][r]) % mod;

	for(int i = 0; i <= 1; ++i)
	  for(int j = 0; j <= 1; ++j)
	    if(!i || !j)
	      incorrect[v] = (incorrect[v] + ways[i][l] * ways[j][r]) % mod;
      }
	
  }

  printf("%d... %d %lld %lld %lld\n", v, type[v], incorrect[v], ways[0][v], ways[1][v]);
}

int main() {
  scanf("%d", &n);

  id = n;

  for(int i = 1; i <= n; ++i) {
    int x, y;
    scanf("%d %d %d", &x, &y, &type[i]);

    if(x)
      adj[i].push_back(x);
    else {
      ++id;
      adj[i].push_back(id);
    }

    if(y) 
      adj[i].push_back(y);
    else {
      ++id;
      adj[i].push_back(id);
    }
  }

  dfs(1);

  printf("%lld\n", incorrect[1]);
  return 0;
}

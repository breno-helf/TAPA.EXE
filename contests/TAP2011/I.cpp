#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr, args)
#define pb push_back

typedef pair<int, int> pii;

const int MAX = 11234;

int n;
vector<int> adj[MAX];
int no, dist;

void dfs (int u, int p, int d) {
  if (d > dist) {
    no = u;
    dist = d;
  }

  for (int v : adj[u]) {
    if (v != p) dfs(v, u, d + 1);
  }
}

int main () {
  while (true) {
    cin >> n;
    if (n == -1) break;
    for (int i = 1; i <= n; i++)
      adj[i].clear();
    
    for (int i = 2; i <= n; i++) {
      int p;
      cin >> p;
      adj[i].pb(p);
      adj[p].pb(i);
    }

    dist = 0;
    no = 1;

    dfs (no, -1, 0);

    dist = 0;
    
    dfs (no, -1, 0);

    cout << (dist + 1) / 2 << '\n';
  }
  
}

#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1e5 + 10;
const int maxk = 20;

int n, m;

map<pii,int> cost;

struct edge {
  int a, b, c;

  bool operator < (const edge &x) const {
    return c < x.c;
  }
};

vector<edge> E;

struct dsu {
  int par[maxn];
  int sz[maxn];

  void init() {
    for(int i = 1; i <= n; ++i) {
      par[i] = i;
      sz[i] = 1;
    }
  }

  int root(int v) {
    if(par[v] == v)
      return v;

    return root(par[v]);
  }

  void merge(int x, int y) {
    x = root(x);
    y = root(y);

    if(x == y)
      return;

    if(sz[y] > sz[x])
      swap(x, y);

    sz[x] += sz[y];
    par[y] = x;
  }
} T;

ll mst;

vector<pii> Tree[maxn];

int h[maxn];
int dp[maxk][maxn];
int edg[maxk][maxn];

void dfs(int v) {
  for(int i = 0; i < Tree[v].size(); ++i) {
    int u = Tree[v][i].first;
    int c = Tree[v][i].second;
    
    if(u == dp[0][v])
      continue;

    dp[0][u] = v;
    h[u] = h[v] + 1;
    edg[0][u] = c;

    dfs(u);
  }
}

void build() {
  sort(E.begin(), E.end());

  T.init();

  for(int i = 0; i < E.size(); ++i) {
    int a = E[i].a;
    int b = E[i].b;
    int c = E[i].c;

    if(T.root(a) == T.root(b))
      continue;

    T.merge(a, b);
    mst += c;

    Tree[a].push_back({b, c});
    Tree[b].push_back({a, c});
  }

  dp[0][1] = 1;
  dfs(1);

  for(int k = 1; k < maxk; ++k)
    for(int i = 1; i <= n; ++i) {
      dp[k][i] = dp[k - 1][dp[k - 1][i]];
      edg[k][i] = max(edg[k - 1][i], edg[k - 1][dp[k - 1][i]]);
    }
}

int lca(int x, int y) {
  if(h[y] < h[x])
    swap(x, y);

  int d = h[y] - h[x];
  int ans = 0;

  for(int k = maxk - 1; k >= 0; --k)
    if((1 << k) & d) {
      ans = max(ans, edg[k][y]);
      y = dp[k][y];
    }

  if(x == y)
    return ans;

  for(int k = maxk - 1; k >= 0; --k)
    if(dp[k][x] != dp[k][y]) {
      ans = max(ans, edg[k][x]);
      ans = max(ans, edg[k][y]);
      x = dp[k][x];
      y = dp[k][y];
    }

  ans = max(ans, edg[0][x]);
  ans = max(ans, edg[0][y]);

  return ans;
}

ll query(int a, int b) {
  return mst - lca(a, b) + cost[{a, b}];
}

int main() {
  scanf("%d %d", &n, &m);

  for(int i = 1; i <= m; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    E.push_back({a, b, c});

    cost[{a,b}] = cost[{b, a}] = c;
  }

  build();

  int q;
  scanf("%d", &q);

  while(q--) {
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%lld\n", query(a, b));
  }
  
  return 0;
}

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAX = (int)1e3 + 10;
const int INF = 0x3f3f3f3f;

bool sub[MAX][MAX];
int sons[MAX];
int n;
vector<int> anc[MAX];
vector<int> adj[MAX];

void dump() {
  for (int v = 1; v <= n; v++) {
    for (int u = 1; u <= n; u++)
      printf("%d ", sub[v][u] ? 1 : 0);
    printf("\n");
  }
}

bool dfs(int u, int p) {
  if (u != p) {
    if (sub[p][u] == false) return false;
    sub[p][u] = false;
  }

  for (int v : adj[u]) {
    if (dfs(v, p) == false) return false;
  }

  return true;
}

bool check() {
  for (int u = 1; u <= n; u++) {
    if (!dfs(u, u)) return false;
    for (int v = 1; v <= n; v++) {
      if (sub[u][v]) return false;
    }
  }
  return true;
}

int main() {
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    int q;
    scanf("%d", &q);
    sons[i] = q;
    for (int j = 0; j < q; j++) {
      int a;
      scanf("%d", &a);
      sub[i][a] = true;
      anc[a].push_back(i);
    }
  }

  for (int v = 1; v <= n; v++) {
    set<int> sz;
    for (int u : anc[v]) {
      if (sz.find(sons[u]) != sz.end()) {
	puts("NO");
	return 0;
      }
      sz.insert(sons[u]);
    }
  }
  
  queue<int> leafs;
  vector<pii> edges;
  int vis = 0;
  
  for (int i = 1; i <= n; i++) {
    if (!sons[i]) leafs.push(i);
  }
  
  
  while (!leafs.empty()) {
    int cur = leafs.front();
    leafs.pop();
    vis++;

    int men = INF;
    int dad = -1;

    // printf("---> %d\n", cur);
    // dump();
    // printf("\n");

    for (int v = 1; v <= n; v++) {
      if (sub[v][cur]) {
	if (sons[v] < men) {
	  dad = v;
	  men = sons[v];
	} else if (sons[v] == men) dad = -1;

	sons[v]--;
	//sub[v][cur] = false;
	
	if (!sons[v]) leafs.push(v);
      }
    }
    
    if (dad == -1) {
      //root = cur;
      break;
    }

    adj[dad].push_back(cur);
    edges.push_back(pii(dad, cur));
  }

  
  
  if (vis == n && (int)edges.size() == (n - 1) && check()) {
    puts("YES");
    sort(edges.begin(), edges.end());
    for (pii e : edges) {
      printf("%d %d\n", e.first, e.second);
    }
  } else puts("NO");

  return 0;
}

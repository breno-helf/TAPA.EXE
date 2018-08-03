#include "bits/stdc++.h"
using namespace std;

#define debug(args...) //fprintf(stderr, args)

typedef pair<int,int> pii;
const int maxn = 5e4 + 10;

int n;
vector<pii> adj[maxn];
vector<int> ans;

bool moveUp[maxn], moveDown[maxn];
int depth[maxn];

void dfs(int v, int par = -1) {
    for(auto i: adj[v]) {
        int u = i.second;
        if(u == par) continue;
        depth[u] = depth[v] + 1;
        dfs(u, v);
    }
}

bool mrk[maxn];
int nodesUp = 0;

void dfsDown(int v, int par = -1, bool flag = false) {
    int newFlag = flag | moveDown[v];
    mrk[v] |= newFlag;
    for(auto i: adj[v]) {
        int u = i.second;
        if(u == par) continue;
        dfsDown(u, v, newFlag);
    }
}

void dfsUp(int v, int par = -1) {
    if(nodesUp) mrk[v] = true;
    if(moveUp[v]) --nodesUp;
    for(auto i: adj[v]) {
        int u = i.second;
        if(u == par) continue;
        dfsUp(u, v);
    }
    
    if(moveUp[v]) ++nodesUp;
}

void solve() {
    dfs(1);
    for(int v = 1; v <= n; ++v) {
        sort(adj[v].begin(), adj[v].end());
        for(int i = 0; i < adj[v].size(); ++i) {
            vector<int> nodes;
            int MAX = INT_MIN;
            int MIN = INT_MAX;
            int j = i;
            while(j < adj[v].size() && adj[v][j].first == adj[v][i].first) {
                nodes.push_back(adj[v][j].second);
                MAX = max(MAX, depth[adj[v][j].second]);
                MIN = min(MIN, depth[adj[v][j].second]);
                ++j;
            }

            debug("nodes of %d color %d\n", v, adj[v][i].first);
            for(auto x: nodes) debug("%d ", x);
            debug("\n");
            debug("-- MAX MIN -- %d %d\n", MAX, MIN);

            if(nodes.size() > 1) {
                if(MIN == MAX) {
                    for(auto u: nodes)
                        moveDown[u] = true;
                }
                else {
                    int u = -1;
                    for(auto node: nodes)
                        if(depth[node] == MIN)
                            u = node;
                    moveUp[u] = true;
                    for(auto node: nodes)
                        if(u != node)
                            moveDown[node] = true;
                }
            }

            i = j - 1;
        }
    }

    for(int i = 1; i <= n; ++i) debug("%d ", depth[i]);
    debug("\n");
                              
    for(int i = 1; i <= n; ++i) debug("%d ", moveDown[i]);
    debug("\n");
    for(int i = 1; i <= n; ++i) debug("%d ", moveUp[i]);
    debug("\n");

    dfsDown(1);

    int node = -1;
    for(int i = 1; i <= n; ++i)
        if(moveUp[i]) 
            ++nodesUp; 

    dfsUp(1);
    
    for(int i = 1; i <= n; ++i) debug("%d ", dp[i]);
    debug("\n");

    for(int v = 1; v <= n; ++v)
        if(!mrk[v])
            ans.push_back(v);
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n - 1; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }
    solve();
    printf("%d\n", (int)ans.size());
    for(auto v: ans) printf("%d\n", v);
    return 0;
}

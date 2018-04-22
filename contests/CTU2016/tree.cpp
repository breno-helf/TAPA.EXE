#include<bits/stdc+.h>
using namespace std;

#define pb push_back

typedef long long ll;
const int MAX = 212;

int n, k;
vector<int> adj[MAX];
int dp1[MAX][MAX];
int dp2[MAX];


int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
}

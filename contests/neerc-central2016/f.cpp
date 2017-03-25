#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 10;

typedef pair < int, int > pii;

int n, m;

int par [MAXN];
int sz [MAXN];

void init ()
{
    for (int i = 1; i <= n; ++i)
    {
        par[i] = i;
        sz[i] = 1;
    }
}

int root (int v)
{
    if (par[v] == v)
        return v;

    return root (par[v]);
}

void merge (int x, int y)
{
    x = root (x);
    y = root (y);

    if (x == y)
        return;

    if (sz[y] > sz[x])
        swap (x, y);

    sz[x] += sz[y];
    par[y] = x;
}

vector < pii > E;

vector < int > adj [MAXN];

map < pii, int > M;

int h [MAXN];
char ans [MAXN];
int deg [MAXN];

void dfs (int v)
{
    h[v] = 1;

    for (int i = 0; i < adj[v].size(); ++i)
    {
        int u = adj[v][i];

        if (h[u] == -1)
            dfs (u);

        h[v] = max (h[v], h[u] + 1);
    }
}

bool mrk[MAXN];
char C[] = {'W', 'R', 'B'};
int H[] = {3, 2, 1};

void DFS (int v, int id)
{
    if (H[id] == h[v])
        ans[v] = C[id];
    else
        return;

    mrk[v] = true;

    for (int i = 0; i < adj[v].size(); ++i)
    {
        int u = adj[v][i];

        if (!mrk[u])
            DFS (u, id + 1);
    }
}

void solve ()
{
    for (int i = 0; i < E.size(); ++i)
    {
        int a = root (E[i].first);
        int b = root (E[i].second);

        if (M.find (pii (a, b)) == M.end())
        {
            adj[a].push_back (b);
            M[pii (a, b)] = 1;
            ++deg[b];
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        ans[i] = '?';
        h[i] = -1;
    }

    for (int i = 1; i <= n; ++i)
        if (h[i] == -1 && !deg[i] && root (i) == i)
            dfs (i);

    for (int i = 1; i <= n; ++i)
        if (h[i] == 3 && !deg[i] && root (i) == i)
            DFS (i, 0);
    
    for (int i = 1; i <= n; ++i)
        ans[i] = ans[root(i)];
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%d %d", &n, &m);

    init();

    for (int i = 1; i <= m; ++i)
    {
        int a, b;
        char c;

        scanf ("%d%c%d", &a, &c, &b);

        if (c == '=')
            merge (a, b);
        else
            if (c == '>')
                E.push_back (pii (a, b));
            else
                E.push_back (pii (b, a));
    }

    solve();

    for (int i = 1; i <= n; ++i)
        printf ("%c", ans[i]);

    return 0;
}

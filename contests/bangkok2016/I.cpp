#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
typedef pair <int, int> pii;

int t, n, q;
vector <int> adj[maxn], g[maxn];

int st[maxn], ed[maxn], sz[maxn];
int id;

vector <pii> queries[maxn];

int ID;

void dfs (int v, int par)
{
	st[v] = ++id;
	sz[v] = 1;

	for (int i = 0; i < adj[v].size(); ++i)
	{
		int u = adj[v][i];

		if (u == par)
			continue;

		dfs (u, v);
		g[v].push_back (u);
		sz[v] += sz[u];
	}

	ed[v] = id;
}

int ans[maxn];

bool cmp (pii x, pii y)
{
	return st[x.first] < st[y.first];
}

int main ()
{
	cin.sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);

	cin >> t;

	int test = 0;
	while (t--)
	{
		int root;
		cin >> n >> q >> root;

		for (int i = 1; i <= n; ++i)
		{
			adj[i].clear();
			queries[i].clear();
			g[i].clear();
		}

		for (int i = 1; i <= n - 1; ++i)
		{
			int a, b;
			cin >> a >> b;
			adj[a].push_back (b);
			adj[b].push_back (a);
		}

		id = 0;

		dfs (1, -1);

		ID = 0;

		for (int i = 1; i <= q; ++i)
		{
			int type, node;
			cin >> type >> node;

			if (type == 0)
				root = node;
			else
			{
				++ID;

				if (st[root] < st[node] || ed[node] < st[root])
					ans[ID] = sz[node];
				else
					if (root == node)
						ans[ID] = n;
					else
						queries[node].push_back (pii (root, ID));
			}
		}

		for (int v = 1; v <= n; ++v)
		{
			sort (queries[v].begin(), queries[v].end(), cmp);

			int pointer = 0;

			for (int i = 0; i < g[v].size(); ++i)
			{
				int u = g[v][i];

				while (pointer < queries[v].size() && st[u] <= st[queries[v][pointer].first] && st[queries[v][pointer].first] <= ed[u])
				{
					int idx = queries[v][pointer].second;
					ans[idx] = n - sz[u];
					++pointer;
				}
			}
		}

		cout << "Case #" << ++ test << ":\n";
		for (int i = 1; i <= ID; ++i)
			cout << ans[i] << '\n';
	}

	return 0;
}

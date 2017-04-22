#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf (stderr, args)

const int maxn = 1e5 + 10;
const int maxN = 1e7;
const int maxk = 30;
const int n = 1e5;

typedef pair <int, int> pii;

int T, N, Q;

vector <pii> adj[maxn];

int dp[maxk][maxn];
int prof[maxn];

int id = 0;
int seg[maxN];
int L[maxN];
int R[maxN];
int root[maxn];

void createNode ()
{
	++id;
	seg[id] = 0;
	L[id] = R[id] = -1;
}

int build (int i, int j)
{
	createNode ();
	int ID = id;

	if (i == j)
		return ID;

	int mid = (i + j) >> 1;

	L[ID] = build (i, mid);
	R[ID] = build (mid + 1, j);

	return ID;
}

int update (int idx, int i, int j, int pos)
{
	createNode ();
	int ID = id;

	R[ID] = R[idx];
	L[ID] = L[idx];
	seg[ID] = seg[idx];

	if (i == j)
	{
		++seg[ID];
		return ID;
	}

	int mid = (i + j) >> 1;

	if (pos <= mid)
		L[ID] = update (L[ID], i, mid, pos);
	else
		R[ID] = update (R[ID], mid + 1, j, pos);

	seg[ID] = seg[L[ID]] + seg[R[ID]];

	return ID;
}

int query (int a, int b, int c, int i, int j, int k)
{
	if (i == j)
		return i;

	int mid = (i + j) >> 1;

	int total = seg[L[a]] + seg[L[b]] - 2 * seg[L[c]];

	if (k <= total)
		return query (L[a], L[b], L[c], i, mid, k);

	return query (R[a], R[b], R[c], mid + 1, j, k - total);
}

void dfs (int v, int par, int lastW)
{
	debug ("dfs(%d)\n", v);

	if (par == -1)
	{
		id = 0;
		root[v] = build (1, n);
	}
	else
	{
		debug ("add (%d %d)\n", root[par], lastW);
		root[v] = update (root[par], 1, n, lastW);
	}

	for (int i = 0; i < adj[v].size(); ++i)
	{
		int u = adj[v][i].first;
		int w = adj[v][i].second;

		if (u == par)
			continue;

		dp[0][u] = v;
		prof[u] = prof[v] + 1;

		dfs (u, v, w);
	}	
}

void compute ()
{
	for (int k = 1; k < maxk; ++k)
		for (int i = 1; i <= N; ++i)
			dp[k][i] = dp[k - 1][dp[k - 1][i]];
}

int lca (int x, int y)
{
	if (prof[y] < prof[x])
		swap (x, y);

	int d = prof[y] - prof[x];

	for (int k = maxk - 1; k >= 0; k--)
		if ((1 << k) & d)
			y = dp[k][y];

	if (x == y)
		return x;

	for (int k = maxk - 1; k >= 0; k--)
		if (dp[k][x] != dp[k][y])
		{
			x = dp[k][x];
			y = dp[k][y];
		}

	return dp[0][x];
}

double get (int a, int b) 
{
	int c = lca (a, b);

	debug ("%d %d %d\n", prof[a], prof[b], prof[c]);
	debug ("%d %d = %d\n", a, b, c);

	int dist = prof[a] + prof[b] - 2 * prof[c];

	a = root[a];
	b = root[b];
	c = root[c];

	if (dist % 2 != 0)
		return query (a, b, c, 1, n, (dist + 1) / 2);
	
	
	double ans = query (a, b, c, 1, n, (dist / 2) + 1);
	ans += query (a, b, c, 1, n, (dist / 2));

	return ans / 2.0;
}

int main ()
{
	cin.sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);

	cin >> T;

	while (T--)
	{
		cin >> N;

		for (int i = 1; i <= N; ++i)
			adj[i].clear();

		for (int i = 1; i <= N - 1; ++i)
		{
			int a, b, w;
			cin >> a >> b >> w;
			adj[a].push_back (pii (b, w));
			adj[b].push_back (pii (a, w));
		}

		dp[0][1] = 1;
		dfs (1, -1, -1);
		compute();

		int q;
		cin >> q;

		for (int i = 1; i <= q; ++i)
		{
			int a, b;

			if (i != 1)
				cout << '\n';

			cin >> a >> b;

			cout << fixed << setprecision (1) << get (a, b);
		}

		if (T != 0)
			cout << '\n';
	}

	return 0;
}

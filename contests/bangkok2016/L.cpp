#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr, args)

const int maxn = 1e5 + 10;

int n, m;

struct pii
{
	int to, dx, dy;
	pii (int to, int dx, int dy) : to(to), dx(dx), dy(dy) {}
};

vector <pii> adj[maxn];

typedef pair <long long, long long> pares;

pares p[maxn];
bool mrk[maxn], marked[maxn];

void dfs (int v)
{
	mrk[v] = true;

	for (int i = 0; i < adj[v].size(); ++i)
	{
		int u = adj[v][i].to;
		int dx = adj[v][i].dx;
		int dy = adj[v][i].dy;

		if (mrk[u])
			continue;

		if (!marked[u])
		{
			marked[u] = true;

			p[u].first = p[v].first + dx;
			p[u].second = p[v].second + dy;
		}

		dfs (u);
	}
}

void fit ()
{
	long long menorx = 1e18;
	long long menory = 1e18;
	long long maiorx = -1e18;
	long long maiory = -1e18;

	for (int i = 1; i <= n; ++i)
	{
		maiorx = max (maiorx, p[i].first);
		maiory = max (maiory, p[i].second);
		

		menorx = min (menorx, p[i].first);
		menory = min (menory, p[i].second);
	}

	if (menorx < -1e9)
		for (int i = 1; i <= n; ++i)
			p[i].first += menorx;
	
	if (maiorx > 1e9)
		for (int i = 1; i <= n; ++i)
			p[i].first -= maiorx;

	if (menory < -1e9)
		for (int i = 1; i <= n; ++i)
			p[i].second -= menory;

	if (maiory > 1e9)
		for (int i = 1; i <= n; ++i)
			p[i].second -= maiory;
}

int main ()
{
	cin.sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);

	cin >> n >> m;

	for (int i = 1; i <= m; ++i)
	{
		int a, b, dx, dy;
		cin >> a >> b >> dx >> dy;

		adj[a].push_back (pii (b, dx, dy));
		adj[b].push_back (pii (a, -dx, -dy));
	}

	p[1] = pares (0, 0);
	marked[1] = true;

	dfs (1);

	// fit();

	for (int i = 1; i <= n; ++i)
		cout << p[i].first << " " << p[i].second << '\n';

	return 0;
}

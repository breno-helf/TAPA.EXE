#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;

int n, m, k;
int g[maxn][maxn];

int c[maxn];

void dfs (int v, int cl)
{
	c[v] = cl;
	for (int i = 1; i <= n; ++i)
		if (!g[v][i] && !c[i])
			dfs(i,cl);
}

int main ()
{
	scanf ("%d%d%d",&n,&m,&k);
	typedef pair <int,int> pii;
	vector <pii> E;
	for (int i = 0; i < m; ++i)	
	{
		int x, y;
		scanf ("%d%d",&x,&y);
		g[x][y]  = g[y][x] = 1;
		E.push_back(pii(x,y));
	}
	int cl = 0;
	for (int i = 1; i <= n; ++i)	
	{
		if(!c[i])
		{
			++cl;
			if (cl > k)
			{
				printf("-1\n");
				return 0;
			}
			dfs(i,cl);
		}		
	}
	for (auto e: E)
		if (c[e.first] == c[e.second])
		{
				printf("-1\n");	
				return 0;
		}

	for (int i = 1; i <= n; ++i)
	printf ("%d ", c[i]);
	printf ("\n");
	
	return 0;
}
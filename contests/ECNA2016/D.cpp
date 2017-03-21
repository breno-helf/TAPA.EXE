#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2 + 10;

typedef pair < int, int > pii;

int N, M;

vector < pii > adj [MAXN];

map < string, int > m;
int id;

bool mrk [MAXN];

long long dis[MAXN];

long long sum;

void dijkstra ()
{
	queue < int > Q;
	
	Q.push (1);
	
	while (!Q.empty())		
	{
		vector < pii > E;
		
		while (!Q.empty())
		{
			int v = Q.front();
			Q.pop();
			
			mrk[v] = true;
			
			for (int i = 0; i < adj[v].size(); ++i)
			{
				int u = adj[v][i].first;
				int c = adj[v][i].second;
				
				if (!mrk[u])
					E.push_back (pii (u, c));
			}
		}
		
		sort (E.begin(), E.end());
		
		for (int i = 0; i < E.size(); ++i)
		{
			int u = E[i].first;
			int c = E[i].second;
			
			if (!mrk[u])
			{
				mrk[u] = true;
				Q.push (u);
				sum += c;
			}	
		}
	}
}

void solve ()
{
	dijkstra();

	for (int i = 1; i <= N + 1; ++i)
		if (!mrk[i])
		{
			printf ("Impossible\n");
			exit (0);
		}
}

int main ()
{
	cin.sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);

	cin >> N >> M;
	
	m["English"] = 1;
	id = 1;
	
	for (int i = 1; i <= N; ++i)	
	{
		string s;
		cin >> s;
		
		m[s] = ++id;
	}
	
	for (int i = 1; i <= M; ++i)
	{
		int u, v;
		
		string a, b;
		int c;
		
		cin >> a >> b >> c;
		
		u = m[a];
		v = m[b];
		
		adj[u].push_back (pii (v, c));
		adj[v].push_back (pii (u, c));
	}
	
	solve ();
	
	cout << sum << '\n';
	
	return 0;
}

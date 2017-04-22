#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf (stderr, args)

const int maxn = 1e3 + 10;
const int maxk = 55;
const long long INF = 1e18;

int s;

struct BIT{
	long long bit[maxn];
	
	void init ()
	{
		for (int i = 1; i <= s; ++i)
			bit[i] = 0;
	}
	
	void add (int idx, long long val)
	{
		while (idx <= s)
		{
			bit[idx] += val;
			idx += (idx & -idx);
		}
	}
	
	long long get (int idx)
	{
		long long ret = 0;
		
		while (idx > 0)
		{
			ret += bit[idx];
			idx -= (idx & -idx);
		}
		
		return ret;
	}
	
} b[maxn];

int n, k;
int a[maxn];

inline void compute (int x)
{
	BIT B;
	B.init();
	
	for (int i = 1; i <= n; i++)
		if (a[i] >= x)
		{
			long long val = B.get (a[i] - 1);
			
			B.add (a[i], +1);
		
			b[x].add (a[i], val);
		}
}

long long dp[maxn][maxk];
long long g[maxn][maxn];

int maior;

void pre ()
{
	for (int i = 1; i <= s; ++i)
		for (int j = i; j <= s; ++j)
		{
			g[i][j] = b[i].get(j);
			//debug ("g[%d][%d] = %lld\n", i, j, g[i][j]);
	
		}	
}

long long f (int pos, int k)
{
	if (dp[pos][k] == -1)
	{
		
		if (pos > s)
		{
			if (!k)
				return dp[pos][k] = 0;
				
			return dp[pos][k] = INF;
		}
		
		if (!k)
			return dp[pos][k] = INF;
		
		dp[pos][k] = INF;
		
		for (int i = pos; i <= s; ++i)
			dp[pos][k] = min (dp[pos][k], g[pos][i] + f (i + 1, k - 1));
	}
	
	return dp[pos][k];
}

int main ()
{
	ifstream cin ("flight.in");
	ofstream cout ("flight.out");
	
	cin.sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	
	cin >> n >> s >> k;
	
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		maior = max (maior, a[i]);
	}
	
	s = maior;
		
	for (int i = 1; i <= s; ++i)
		compute (i);
		
	pre();
		
	memset (dp, -1, sizeof (dp));
	
	cout << f (1, k) << '\n';
	
	return 0;
}

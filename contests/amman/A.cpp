 #include <bits/stdc++.h>
using namespace std;

const int maxw = 15000 + 10;
const int maxn = 150 + 10;
const long long mod = 1e9 + 7;

int n[2], K, w;

int a[2][maxn];
long long dp[2][maxw][maxn];

long long f (int id, int W, int i)
{
	if (dp[id][W][i] == -1)
	{
		if (!W)
			return (dp[id][W][i] = 1);
	
		if (!i)
			return (dp[id][W][i] = 0);
			
		dp[id][W][i] = 0;
		
		dp[id][W][i] = f (id, W, i - 1);
		
		if (W >= a[id][i])
			dp[id][W][i] = (dp[id][W][i] + f (id, W - a[id][i], i - 1)) % mod;
	}
	
	return dp[id][W][i];
}

int main ()
{
	int t;
	scanf ("%d", &t);
	
	while (t--)
	{
		scanf ("%d %d %d %d", &n[0], &n[1], &K, &w);
		
		for (int k = 0; k < 2; ++k)
			for (int i = 1; i <= n[k]; ++i)
				scanf ("%d", &a[k][i]);
			
		memset (dp, -1, sizeof (dp));		
	
		long long ans = 0;
		for (int i = 0; i <= w; ++i)
		{
			int c1 = i;
			int c2 = w - i;
		
			if (abs (c1 - c2) <= K)
			{
				long long p1 = f (0, c1, n[0]);
				long long p2 = f (1, c2, n[1]);
				ans = (ans + ((p1 * p2) % mod)) % mod;
			}
		}
	
		printf ("%lld\n", ans);
	}
	
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int maxm = 1e4 + 10;
const int maxn = 1e2 + 10;

int n, m, k;

int dp[maxm][maxn], a[maxn];

inline int f (int sum, int i)
{
	if (dp[sum][i] == -1)
	{
		if (!i)
		{
			if (!sum)
				return (dp[sum][i] = 1);
			return (dp[sum][i] = 0);
		}
		
		dp[sum][i] = f (sum, i - 1);
		
		if (sum >= a[i])
			dp[sum][i] += f (sum - a[i], i - 1);
			
		dp[sum][i] = min (dp[sum][i], k);
	}
	return dp[sum][i];
}

void solve ()
{
	memset (dp, -1, sizeof (dp));
	int cmp = f (m, n);
	if (cmp >= k)
		printf ("ENOUGH\n");
	else
		printf ("%d\n", cmp);
}

int main ()
{
	int t;
	scanf ("%d", &t);
	while (t--)
	{
		scanf ("%d %d %d", &n, &m, &k);
		for (int i = 1; i <= n; ++i)
			scanf ("%d", &a[i]);
		solve();
	}
	return 0;	
}

#include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 10;
typedef pair <long long, long long> pii;

#define debug(args...) fprintf (stderr, args)

int a[N][N];
long long dp[N][N];

int n, m;

void computeDP ()
{
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			dp[i][j] = 1;
			
			if (a[i][j] == a[i - 1][j])
				dp[i][j] += dp[i - 1][j];
		}
}

long long solve ()
{
	long long ans = 0LL;
	
	for (int i = 1; i <= n; ++i)
	{
		vector <pii> stk;
		
		int colour = 0;
		long long total = 0LL;
		int sz;
		
		for (int j = 1; j <= m; ++j)
		{
			if (a[i][j] != colour)
			{
				stk.clear();
				total = 0LL;
				stk.push_back (pii (0, 0));
				colour = a[i][j];
				sz = 0;
			}
		
			long long len = 1;		
			long long height = dp[i][j];
			
			while (!stk.empty() && stk.back().first >= dp[i][j])
			{
				len += stk.back().second;
				
				total -= (stk[sz].first * stk[sz].second);
				
				stk.pop_back();
				--sz;
			}
			
			stk.push_back (pii (height, len));
			++sz;
			
			// add
			total += (stk[sz].first * stk[sz].second);
			
			ans += total;
		}
	}
	
	return ans;
}

int main()
{
    int t;
    scanf("%d", &t);

 	while (t--)
	{
		scanf ("%d %d", &n, &m);
		
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				scanf ("%d", &a[i][j]);
		
		computeDP();
		printf ("%lld\n", solve());
	}
	
	return 0;
    
}

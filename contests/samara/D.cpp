#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

int n, a[maxn], m;
int ans = -1;

map <int,int> freq;

int main ()
{
	scanf ("%d",&n);
	for (int i = 1; i <= n; ++i)
	{		
		scanf ("%d",&a[i]);	
		++freq[a[i]];
		if (freq[a[i]] == n)
			ans = 0;
	}
	scanf ("%d", &m);
	int t = 0;
	while (m--)
	{
		int x, y;
		++t;
		scanf ("%d%d",&x,&y);
		--freq[a[x]];
		a[x] = y;
		++freq[y];
		if (freq[y] == n && ans == -1)
			ans = t;
	}
	printf ("%d\n",ans);
	return 0;
}

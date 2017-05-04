#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr, args)

struct pii
{
	int p, x;
	pii (int p, int x) : p(p), x(x) {}
};

bool operator < (pii A, pii B)
{
	return (A.p > B.p) || (A.p == B.p && A.x < B.x);
}

int t;

int n, q;

int main ()
{
	scanf ("%d", &t);
	
	while (t--)
	{
		scanf ("%d %d", &n, &q);
		
		multiset <pii> Q;
		map <int, int> score;
		
		int ans = 0;
		int last = 1;
		
		for (int i = 1; i <= n; ++i)
		{
			score[i] = 0;
			Q.insert (pii (0, i));
		}
		
		for (int i = 1; i <= q; ++i)
		{
			int x, p;
			scanf ("%d %d", &x, &p);
			
			Q.erase (pii (score[x], x));		
			
			score[x] += p;
			Q.insert (pii (score[x], x));
			
			int leader = Q.begin()->x;
			
			if (leader != last)
				ans = i;
			
			last = leader;
		}
		
		printf ("%d\n", ans);
	}
	
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr, args)

const int maxn = 1e5 + 10;
const int MASK = (1 << 9) + 10;

int t, n, q;

int a[maxn];

int m[maxn]; // divisores de m
int d[MASK][maxn];

inline void compute ()
{
	for (int k = 1; k < MASK; ++k)
		for (int i = 1; i <= n; ++i)
		{
			d[k][i] = d[k][i - 1];

			if ((m[i] & k))
				++d[k][i];
		}
}

int main ()
{
	scanf ("%d", &t);

	while (t--)
	{
		scanf ("%d %d", &n, &q);

		for (int i = 1; i <= n; ++i)
		{
			scanf ("%d", &a[i]);

			m[i] = 0;
			for (int k = 2; k <= 10; ++k)
				if (a[i] % k == 0)
					m[i] += (1 << (k - 2));
		}

		compute();

		while (q--)
		{
			int l, r;
			scanf ("%d %d", &l, &r);

			int s;
			scanf ("%d", &s);

			if ((1 << 0) & s)
			{
				printf ("%d\n", r - l + 1);
				continue;
			}

			s /= 2;

			printf ("%d\n", d[s][r] - d[s][l - 1]);
		}
	}

	return 0;
}

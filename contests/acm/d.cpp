#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 10;

int t, n;

bool prime[MAXN];
int sum[MAXN];

void sieve ()
{
	prime[1] = false;
	for (long long i = 2; i * i < MAXN; ++i)
		if (!prime[i])
			for (long long j = i * i; j < MAXN; j += i)
				prime[j] = true;
	for (int i = 1; i < MAXN; ++i)
		sum[i] = sum[i - 1] + (prime[i] == false);
}

int main ()
{
	scanf ("%d", &t);
	sieve();
	int T = 0;
	while (t--)
	{
		scanf ("%d", &n);
		printf ("Case #%d: %d\n", ++T, sum[n]);
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int t;
	scanf ("%d", &t);

	while (t--)
	{
		int num;
		scanf ("%d", &num);
		printf ("%d\n", num / 5 + (num % 5 != 0));
	}

	return 0;
}


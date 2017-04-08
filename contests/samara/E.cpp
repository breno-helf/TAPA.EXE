#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	string s;
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	n = s.size();

	if (n % 2 != 0)
		printf ("NO\n");
	else
	{
			map <char, int> f;
			int maior = 0;
			for (int i = 0; i < s.size(); ++i)
				++f[s[i]];
			for (char c = 'a'; c <= 'z'; ++c)
				maior = max (maior, f[c]);
			if  (maior > n / 2)
				printf ("NO\n");
			else
				printf ("YES\n");
	}
	return 0;
}

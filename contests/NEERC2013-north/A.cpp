#include <bits/stdc++.h>
using namespace std;

map <char, int> m;

int main ()
{
	ifstream cin ("arrange.in");
	ofstream cout ("arrange.out");
	
	cin.sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	
	int n;
	cin >> n;
	
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		++m[s[0]];
	}
	
	char c = 'A';
	for (int i = 1; i <= 26; ++i)
	{
		if (!m[c])
		{
			cout << i - 1 << '\n';
			return 0;
		}
		++c;
	}
		
	cout << 26 << '\n';
	return 0;

}

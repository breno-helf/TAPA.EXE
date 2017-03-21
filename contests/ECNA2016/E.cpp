#include <bits/stdc++.h>
using namespace std;

string s;

bool ok (int x, string &S)
{
	if (x + S.size() - 1 >= s.size())
		return false;

	for (int i = x, j = 0; j < S.size(); ++j, ++i)
		if (s[i] != S[j])
			return false;
		
	return true;
}

int solve (int l, int r)
{
	string S;
	
	for (int i = l; i <= r; ++i)
		S.push_back (s[i]);
	
	int ans = S.size();	
	for (int i = 0; i < s.size(); ++i)
	{
		++ans;
		
		if (ok (i, S))
			i += (S.size() - 1);
	}
	
	return ans;
}

int main ()
{
	cin.sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	
	cin >> s;
	
	int ans = s.size();
	for (int i = 0; i < s.size(); ++i)
		for (int j = i; j < s.size(); ++j)
			ans = min (ans, solve (i, j));
			
	cout << ans << '\n';
	return 0;
}

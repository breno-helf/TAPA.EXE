#include <bits/stdc++.h>
using namespace std;

int t;
string s;

int c[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main ()
{
	cin.sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);

	cin >> t;

	while (t--)
	{
		int n;
		cin >> n >> s;

		int sum = 0;

		for (int i = 0; i < s.size(); ++i)
			sum += c[s[i] - '0'];
		
		string ans;

		for (int N = n; N >= 1; N--)
		{
			for (int d = 9; d >= 0; d--)
				if (2 * (N - 1) <= sum - c[d] && sum - c[d] <= 7 * (N - 1))
				{
					ans.push_back (d + '0');
					sum -= c[d];
					break;
				}				
		}

		cout << ans << '\n';
	}

	return 0;
}

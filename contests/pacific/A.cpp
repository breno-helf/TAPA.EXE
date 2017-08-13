#include "bits/stdc++.h"
using namespace std;

const int maxn = 55;
const int INF = 0x3f3f3f3f;

string s;
int n, dp[maxn][30], a[maxn];

int f(int i, int last) {
	if(dp[i][last] == -1) {
		if(last > 25)
			return dp[i][last] = 0;

		if(i >= n)
			return dp[i][last] = 26 - last;

		dp[i][last] = f(i + 1, last);

		if(last <= a[i])
			dp[i][last] = min(dp[i][last], f(i + 1, a[i] + 1) + a[i] - last);
	}

	return dp[i][last];
}

int main() {
	cin >> s;
	
	n = (int)s.size();
	memset(dp, -1, sizeof(dp));

	for(int i = 0; i < n; ++i)
		a[i] = s[i] - 'a';

	cout << f(0, 0) << '\n';
	return 0;
}

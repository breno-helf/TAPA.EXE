#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 112;

string s;
int n;
ll dp[MAX][12][2][2];

ll solve (int i, int last, int c, int men) {
    ll &res = dp[i][last][c][men];

    if (res != -1) return res;
    
    if (i == n) return res = (men == 1) ? 1LL : 0LL;
    
    if (c == 1) {
	res = 0;
	int cur = s[i] - '0';
		
	for (int j = 0; j < cur; j++) {
	    res = (res + solve(i + 1, j, (j < last) ? 0 : 1, max(men, 1))); 
	}

	res = (res + solve(i + 1, cur, (cur < last) ? 0 : 1, max(men, 0)));
	
	if (men == 1) {
	    for (int j = cur + 1; j <= 9; j++) {
		res = (res + solve(i + 1, j, (j < last) ? 0 : 1, max(men, 0)));
	    }
	}
	
	return res;
    } else {
	res = 0;

	int cur = s[i] - '0';
	
	
	
	for (int j = 0; j <= last; j++) {
	    if (j < cur) {
		res = (res + solve(i + 1, j, 0, max(men, 1)));
	    } else if (j == cur) {
		res = (res + solve(i + 1, j, 0, max(men, 0)));
	    } else if (j > cur && men) {
		res = (res + solve(i + 1, j, 0, max(men, 0)));
	    }
	}

	return res;
    }
    
}

bool check () {
    int c = 1;
    for (int i = 1; i < n; i++) {
	if (s[i] > s[i - 1]) {
	    if (c == 0) return false;
	} else if (s[i] < s[i - 1]) {
	    c = 0;
	}
    }
    return true;
}

int main () {
    int t;
    cin >> t;
    while (t--) {
	cin >> s;
	n = s.size();
	memset(dp, -1, sizeof(dp));
	if (check())
	    cout << solve(0, 0, 1, 0) << '\n';
	else cout << -1 << '\n';
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;
typedef pair<ll, ll> pll;

const int MAX = 212;

int dp[MAX][MAX][22];
char s[MAX];
int n;

// 0 - Nada
// 1 - Abre set
// 2 - Fecha set
// 3 - elemento
// 4 - virgula

int solve (int i, int q, int last) {
    int &res = dp[i][q][last];
    if (res != -1) return res;

    // Caso Base
    
    if (i == n - 1) {
	return res = (q == 0 && (last == 0 || last == 2 || last == 3));
    }
    
    if (s[i] == '{') {
	if (last == 0 || last == 1) {
	    return res = solve(i + 1, q + 1, 1) || solve(i + 1, q, 3);
	} else if (last == 3 || last == 2) {
	    return res = 0;
	} else if (last == 4) {
	    return res = solve(i + 1, q, 3);
	}
    } else if (s[i] == '}') {
	if (last == 0 || last == 1) {
	    if (q == 0)
		return res = solve(i + 1, q, 3);
	    else 
		return res = solve(i + 1, q, 3) || solve(i + 1, q - 1, 2);
	} else if (last == 3 || last == 2) {
	    if (q == 0)
		return res = 0;
	    else
		return res = solve(i + 1, q - 1, 2);
	} else if (last == 4) {
	    return res = solve(i + 1, q, 3);
	}
    } else {
	if (last == 0 || last == 1) {
	    return res = solve(i + 1, q, 3);
	}
	else if (last == 2 || last == 3) {
	    return res = solve(i + 1, q, 4);
	} else if (last == 4) {
	    return res = solve(i + 1, q, 3);
	}
    }

    return 0;
}

int main () {
    int t;
    scanf ("%d", &t);
    for (int T = 1; T <= t; T++) {
	memset(dp, -1, sizeof(dp));
	scanf (" %s", s);
	n = strlen(s);
	if (s[0] == '{' && s[n - 1] == '}') {
	    printf ("Word #%d: %s\n", T, (solve(1, 0, 0) == 1) ? "Set" : "No Set");
	} else {
	    printf ("Word #%d: %s\n", T, "No Set");

	}
    }
    return 0;
}

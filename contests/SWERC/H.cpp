//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 21092013;

ll dp[MAX];
int R[MAX], L[MAX];
string a, b;
int n;

ll solve (int i) {
    ll &res = dp[i];
    if (i > n) return 0;
    if (res != -1) return res;
    return res = (solve(L[i]) + solve(R[i]) + 1LL) % MOD;
}

int main () {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(0);

    int t;
    
    cin >> t;

    for (int T = 1; T <= t; T++) {
	memset(dp, -1, sizeof(dp));
	memset(R, -1, sizeof(R));
	memset(L, -1, sizeof(L));

	cin >> a >> b;
	
	stack<char> moves;
	vector<int> U;
	for (int i = 0; i < (int)a.size(); i++) {
	    if (a[i] == 'U' && !moves.empty()) {
		moves.pop();
	    } else moves.push(a[i]);
	}
	n = b.size();
	int lastR, lastL;
	lastR = lastL = n + 1;
	
	for (int i = n; i >= 0; i--) {
	    R[i] = lastR;
	    L[i] = lastL;

	    if (i > 0) {
		if (b[i - 1] == 'L') lastL = i;
		else if (b[i - 1] == 'R') lastR = i;
		else U.pb(i);
	    }
	}

	ll resp = solve(0);

	sort(U.begin(), U.end());
	
	for (int u : U) {
	    if (moves.empty()) break;
	    if (moves.top() == 'L') resp = (resp + solve(R[u - 1]) + 1LL) % MOD;
	    else if (moves.top() == 'R') resp = (resp + solve(L[u - 1]) + 1LL) % MOD;
	    
	    moves.pop();
	}
	resp %= MOD;
	cout << "Case " << T << ": ";
	cout << resp << '\n';
    }
    return 0;
}


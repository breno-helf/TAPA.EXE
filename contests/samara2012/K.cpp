//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

string s;
int a[MAX], b[MAX];
int u, t;
int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++) {
	if (i) {
	    a[i] = a[i - 1];
	}

	if (s[i] == '1') {
	    a[i]++;
	}
    }

    for (int i = (int)s.size() - 1; i >= 0; i--) {
	if (i != (int)s.size() - 1)
	    b[i] = b[i + 1];

	if (s[i] != '1') b[i]++;
    }
    int resp = b[0];
    for (int i = 0; i < (int)s.size(); i++) {
	resp = min(resp, b[i + 1] + a[i]);
    }
    cout << resp << '\n';
}

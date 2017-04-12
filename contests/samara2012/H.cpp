//If you are trying to hack me I wish you can get it, Good Luck :D
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
const ll  MOD = 1000000007;

int k;
int c[MAX][30];
string s;

bool go (int t, int e) {
    int num = 0;
    for (int i = 0; i < 26; i++) {
	int h = t ? c[t - 1][i] : 0;
	if((c[e][i] - h) > 0) num++;	
    }
    // debug ("%d %d -- %d\n", t, e, num);
    return (num <= k);
}

int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    cin.sync_with_stdio(false);
    cin >> k >> s;
    for (int i = 0; i < (int)s.size(); i++) {
	if (i > 0)
	    for (int j = 0; j < 26; j++) c[i][j] = c[i - 1][j];
	c[i][s[i] - 'a']++;
    }
    int m = 0;
    int L = -1, R = -1;
    for (int i = 0; i < (int)s.size(); i++) {
	int l = i, r = s.size() - 1;
	while (l < r) {
	    int mid = (l + r + 1) / 2;
	    if (!go(i, mid)) r = mid - 1;
	    else l = mid;
	}
	if ((l - i + 1) > m) {
	    m = (l - i + 1);
	    L = i;
	    R = l;
	}
    }
    cout << L + 1 << ' ' << R + 1 << '\n';
}


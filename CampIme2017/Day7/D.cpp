//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 12312;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int t;

bool test (string s) {
    set<string> sub;
    int n = s.size();
    for (int i = 0; i < n; i++) {
	string cur = "";
	for (int j = i; j < n; j++) {
	    cur += s[j];
	    sub.insert(cur);
	}
    }

    for (int i = 0; i < n; i++) {
	string cur = "";
	for (int j = i; j < n; j++) {
	    cur += s[j];
	    string at = cur;
	    reverse(at.begin(), at.end());
	    if (sub.find(at) == sub.end()) return false;
	}
    }


    return true;
}

int main () {
    cin >> t;
    while (t--) {
	string s;
	cin >> s;
	if (test(s)) cout << "YES" << '\n';
	else cout << "NO" << '\n';
    }
    return 0;
}


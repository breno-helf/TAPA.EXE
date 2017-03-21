#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<string, string> pss;

const int MAX = 12;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

string s[MAX];
int n;
string game;

int main () {
    cin.sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
	cin >> s[i];
    }

    cin >> game;
    vector<pss> resp;
    queue<string> Q;
    int Dw, Db;
    pss W = pss(s[0], s[2]);
    pss B = pss(s[1], s[3]);
    string w1, w2, b1, b2;
    w1 = s[0]; w2 = s[2];
    b1 = s[1]; b2 = s[3];
    for (int i = 4; i < n; i++) Q.push(s[i]);
    int mx = 0;
    Dw = Db = 0;
    for (char c : game) {
	debug("--> (%s, %s) wins %d and (%s, %s) wins %d\n", W.first.c_str(), W.second.c_str(), Dw, B.first.c_str(), B.second.c_str(), Db);
	if (c == 'W') {
	    Dw++;

	    if (Dw == mx) {
		resp.pb(pss(w1, w2));
	    }
	    else if (Dw > mx) {
		resp.clear();
		mx = Dw;
		resp.pb(pss(w1, w2));
	    }
	    Db = 0;
	    assert(!Q.empty());
	    Q.push(B.second);
	    B = pss(Q.front(), B.first);
	    b1 = B.second;
	    b2 = Q.front();
	    debug("Inserting %s\n", Q.front().c_str());
	    W = pss(W.second, W.first);
	} else {
	    Db++;

	    if (Db == mx) {
		resp.pb(pss(b1, b2));
	    }
	    else if (Db > mx) {
		resp.clear();
		mx = Db;
		resp.pb(pss(b1, b2));
	    }
	    Dw = 0;
	    assert(!Q.empty());
	    Q.push(W.second);
	    W = pss(Q.front(), W.first);
	    debug("Inserting %s\n", Q.front().c_str());
	    w1 = W.second;
	    w2 = Q.front();
	    B = pss(B.second, B.first);
	}
	debug("--> (%s, %s) wins %d and (%s, %s) wins %d\n", W.first.c_str(), W.second.c_str(), Dw, B.first.c_str(), B.second.c_str(), Db);
	debug("\n");
	Q.pop();
    }

    for (auto e : resp) {
	cout << e.first << ' ' << e.second << '\n';
    }
    return 0;
}



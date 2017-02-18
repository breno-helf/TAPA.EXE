//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 4123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

string s, t;

vector< vector<int> > mapa (string S, int tam) {
    vector < vector<int> > ret;
    vector<int> num(26, 0);
    for (int i = 0; i < tam - 1; i++)
	num[S[i] - 'a']++;

    for (int i = 0; (i + tam) <= (int)S.size(); i++) {
	num[S[i + tam - 1] - 'a']++;
	ret.pb(num);
	num[S[i] - 'a']--;
    }
    return ret;
}

int solve () {
    int sT = s.size(), tT = t.size();
    int tam = min(sT, tT);
    for (int i = tam; i > 0; i--) {
	vector< vector<int> > A = mapa(s, i), B = mapa(t, i);
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int a = 0, b = 0;
	while (a < A.(int)size() && b < (int)B.size()) {
	    if (A[a] == B[b])
		return i;
	    if (A[a] < B[b]) {
		a++;
	    } else b++;	    
	}
    }
    return 0;
}

int main () {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> t;

    cout << solve() << '\n';
}


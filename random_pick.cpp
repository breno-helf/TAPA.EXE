//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 412312;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int main() {
    srand(time(NULL));
    vector<string> v;
    freopen("ContestToDo", "r", stdin);
    string s;
    while (getline(cin, s))
	v.pb(s);
    random_shuffle(v.begin(), v.end());
    cout << v[0] << '\n';
}


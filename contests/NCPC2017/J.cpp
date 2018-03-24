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

int l, r;

int main() {
    cin >> l >> r;
    if (l == r && l != 0) {
	cout << "Even " << 2 * l << '\n';
    } else if (l != 0 || r != 0) {
	cout << "Odd " << 2 * max(r, l) << '\n';	
    } else {
	cout << "Not a moose\n";
    }
    
    return 0;
}


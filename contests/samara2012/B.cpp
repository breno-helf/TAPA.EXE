//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 22;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n;
int a[MAX];

int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    cin.sync_with_stdio(false);

    int x = 0;
    
    cin >> n;
    for (int i = 0; i < n; i++)
	cin >> a[i];

    for (int i = 0; i < n; i++) {
	x += (a[i]);
    }
    // debug("%d\n", x);
    if (x % 2 != n % 2) cout << "Constantine" << '\n';
    else cout << "Mike" << '\n';
}


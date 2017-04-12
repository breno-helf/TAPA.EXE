//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 2123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, k;
pii c[MAX];
int resp[MAX];
int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    scanf ("%d%d", &k, &n);
    for (int i = 0; i < n; i++) {
	int a;
	scanf ("%d", &a);
	c[i] = pii(a, i);
    }
    sort (c, c + n);
    for (int i = 0; i < n; i++) {
	if (k == 0) break;
	resp[c[i].second] = min(c[i].first, k);
	k = max(k - c[i].first, 0);
    }
    for (int i = 0; i < n; i++)
	printf ("%d ", resp[i]);

    printf("\n");
    return 0;
}


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
const ll  MOD = 1000000007;

ll n, d, a, b, c, s;
ll p[MAX];

int main() {
    scanf ("%lld %lld %lld %lld", &n, &d, &a, &b);
    s = c = 0;

    for (int i = 1; i <= n; i++) {
	scanf ("%lld", p + i);
    }

    //debug ("1 -- %lld %lld\n", d, s);
    
    for (int i = 2; i <= n; i++) {
	if (p[i] > p[i - 1]) {
	    c = max(c, 0LL);
	    c++;
	    if (a * c * p[i] <= d) {
		s += a * c;
		d -= a * c * p[i];
	    } else {
		ll m = d / p[i];
		s += m;
		d -= m * p[i];
	    }
	}

	else if (p[i] < p[i - 1]) {
	    c = min(c, 0LL);
	    c--;
	    if (- b * c <= s) {
		d += - b * c * p[i];
		s -= - b * c;
	    } else {
		d += s * p[i];
		s = 0;
	    }
	}

	//else if (p[i] == p[i - 1]) c = 0;

	//debug ("%lld -- %lld %lld\n", i, d, s);
    }

    printf ("%lld %lld\n", d, s);
}


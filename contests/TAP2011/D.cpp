#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n;
ll m, c[MAX];
ll acc[MAX];


int main () {
    while (true) {
	scanf ("%d %lld", &n, &m);
	if (n == -1) break;
	for (int i = 1; i <= n; i++) {
	    scanf ("%lld", c + i);
	    acc[i] = acc[i - 1];
	    acc[i] += c[i];
	}

	ll resp = 0;
	
	for (int i = 1; i <= n; i++) {
	    resp += acc[i] * m;
	}

	printf ("%lld\n", resp);
    }

    return 0;
}



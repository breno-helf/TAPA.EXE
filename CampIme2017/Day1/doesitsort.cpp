#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define FOR(i,a,b) for(int i = a; i <= b; ++i)

typedef long long ll;
typedef pair<int, int> pii;

const ll INF = 1e17;
const int MAX = 250000 + 10;

int n, m;
ll cnt[MAX];

ll fexp (int a, int e) {
    ll ret = 1, pow = a;
    for (int i = 0; i <= 30; i++){
	if (e & (1 << i)){
	    ret *= pow;
	    ret %= m;
	}
	pow *= pow;
	pow %= m;
    }
    return ret;
}

int main () {
    scanf ("%d %d", &n, &m);
    for (int i = 1; i < m; i++) {
	cnt[fexp(i, n)]++;
    }

    ll resp = 0;
    
    for (int i = 0; i < m; i++) {
	if (
    }
}

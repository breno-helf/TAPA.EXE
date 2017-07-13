#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;
typedef pair<ll, ll> pll;

const int MAX = 1e6 + 10;

struct festa {
    ll D, x, y;
    festa (ll a, ll b, ll c) {
	D = a;
	x = b;
	y = c;
    }

    festa () {
	D = x = y = 0;
    }

    bool operator < (const festa ot) const {
	if (ot.D == D) {
	    if (ot.x == x) {
		return y < ot.y;
	    } else return x < ot.x;
	} else return D < ot.D;
    }
}resp[MAX];

ll x[MAX], y[MAX];
vector<pll> X, Y;

int r;

void deb () {
    for (int i = 0; i < (int)X.size(); i++) {
	printf ("%lld ", resp[i].D);
    }
    printf ("\n");
}

int main () {
    scanf ("%d", &r);
    
    for (int i = 0; i < r; i++) {
	ll x1, y1, x2, y2;
	scanf ("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
	for (int a = x1; a <= x2; a++) {
	    for (int b = y1; b <= y2; b++) {
		int id = X.size();
		resp[id] = festa(0, a, b);
		X.pb(pll(a, id));
		Y.pb(pll(b, id));	
	    }
	}
    }
    
    int tot = X.size() - 1;

    // for (int i = 0; i <= tot; i++) {
    // 	for (int j = 0; j <= tot; j++) {
    // 	    resp[i].D += abs(X[i].first - X[j].first) + abs(Y[i].first - Y[j].first);
    // 	}
    // }

    
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    for (int i = 0; i < (int)X.size(); i++) {
    	if (i != 0) {
    	    x[i] = x[i - 1];
    	    y[i] = y[i - 1];
    	}
    	else y[i] = x[i] = 0;
    	x[i] += X[i].first;
    	y[i] += Y[i].first;

    }
    
    for (int i = 0; i < (int)X.size(); i++) {
    	if (i != tot) {
    	    resp[X[i].second].D += abs(x[tot] - x[i] - (tot - i) * X[i].first);
	    
    	    //printf ("Adding %lld to %lld\n", abs(x[tot] - x[i] - (tot - i) * X[i].first), X[i].second);
	    
    	    resp[Y[i].second].D += abs(y[tot] - y[i] - (tot - i) * Y[i].first);

    	    //printf ("Adding %lld to %lld\n", abs(y[tot] - y[i] - (tot - i) * Y[i].first), Y[i].second);
	    
    	}

    	if (i > 0) {
    	    resp[X[i].second].D += abs(- x[i - 1] + (i) * X[i].first);

	    //printf ("--> %lld %lld %lld ", x[i - 1], (i), X[i].first);
	    
    	    //printf ("Adding %lld to %lld\n", abs(- x[i - 1] + (i) * X[i].first), X[i].second);
	    
    	    resp[Y[i].second].D += abs(- y[i - 1] + (i) * Y[i].first);

    	    //printf ("Adding %lld to %lld\n", abs(- y[i - 1] + (i - 1) * Y[i].first), Y[i].second);

    	}
    }

    sort(resp, resp + tot);
    
    printf ("%lld\n", resp[0].D);

    printf ("%lld %lld\n", resp[0].x, resp[0].y);
    
    return 0;
}

    

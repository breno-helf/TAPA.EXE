//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 312345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, m;

double r;

vector<double> c, x;

int L[MAX], R[MAX];

double dist(double A, double B) {
    if (A == B) return 1;
    return 1 + (B - A) * (B - A);
}

void precalc(int i) {
    int cur = lower_bound(c.begin(), c.end(), x[i]) - c.begin();
    int best = cur;
    int lo = 0;
    int hi;

    for (int k = -1; k <= 1; k++) {
	if (cur + k < 0 || cur + k >= m) continue;
	if (dist(c[cur + k], x[i]) < dist(c[best], x[i]))
	    best = cur + k;
    }

    hi = best;

    while (lo < hi) {
	int mid = (lo + hi) / 2;
	if (dist(c[mid], x[i]) <= r * r) hi = mid;
	else lo = mid + 1;
    }

    L[i] = lo;

    lo = best;
    hi = m - 1;

    while (lo < hi) {
	int mid = (lo + hi + 1) / 2;
	if (dist(c[mid], x[i]) <= r * r) lo = mid;
	else hi = mid - 1;
    }

    R[i] = lo;
}

int main() {
    scanf("%d %d %lf", &m, &n, &r);

    for (int i = 0; i < m; i++) {
	double A;
	scanf("%lf", &A);
	c.pb(A);
    }
    for (int i = 0; i < n; i++) {
	double A;
	scanf("%lf", &A);
	x.pb(A);
    }
    for (int i = 0; i < n; i++) {
	precalc(i);
	debug ("--- %d %d\n", L[i], R[i]);
    }

    int cur = 0;
    double resp = 0;
    for (int i = 0; i < n; i++) {
	if (cur >= L[i] && cur <= R[i]) continue;
	else if (cur < L[i]) {
	    debug (">> %lf\n", c[L[i]] - c[cur]);
	    resp += c[L[i]] - c[cur];
	    cur = L[i];
	} else if (cur > R[i]) {
	    debug (">|> %lf\n", c[R[i]] - c[cur]);
	    resp += c[cur] - c[R[i]];
	    cur = R[i];
	}
    }

    printf ("%lf\n", resp);
    return 0;
}

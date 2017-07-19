#include <bits/stdc++.h>
using namespace std;

const int MAX = 112345;

typedef long long ll;

int n, m;
double a[MAX];
double L[MAX], R[MAX];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
	scanf ("%lf", &a[i]);
    }

    sort(a, a + n);
    
    for (int i = 0; i < n; i++) {
	L[i] = -0.9 * a[i];
	R[i] = -1.1 * a[i];
	//printf ("--> %lf %lf\n", L[i], R[i]);
    }
    reverse(L, L + n);
    reverse(R, R + n);
    scanf ("%d", &m);

    for (int i = 0; i < m; i++) {
	double q;
	scanf ("%lf", &q);
	int l = lower_bound(L, L + n, -q) - L; 
	int r = upper_bound(R, R + n, -q) - R;
	//l = upper_bound(L, L + n, q) - L;
	//r = upper_bound(R, R + n, R[r]) - R;
	//printf ("--> %d %d\n", l, r);
	printf ("%d\n", max(r - l, 0));
    }
    return 0;
}

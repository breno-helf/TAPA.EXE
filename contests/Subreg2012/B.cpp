#include<bits/stdc++.h>
using namespace std;

const int MAX = 1123;
const double eps = 1e-9;

int n;
double l, h;

double Xf[MAX], Yi[MAX], Yf[MAX];

inline int cmp(double x, double y = 0, double tol = eps) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct point {
    double x, y;
    point(double X = 0, double Y = 0): x(X), y(Y) {}
    point operator +(point q) { return point(x + q.x, y + q.y); }
    point operator -(point q) { return point(x - q.x, y - q.y); }
    double operator *(point q) { return (x * q.x + y * q.y); }
    double operator %(point q) { return (x * q.y - y * q.x); }
};

double seg_dist(point p, point q, point r) {
    point A = r - q, B = r - p, C = q - p;

    double a = A * A, b = B * B, c = C * C;

    if (cmp(b, a + c) >= 0) return sqrt(a);
    else if (cmp(a, a + c) >= 0) return sqrt(b);
    else return fabs(A % B) / sqrt(c);
}

int main() {
    while (scanf("%d", &n) != EOF) {
	scanf("%lf %lf", &l, &h);
	
	for (int i = 1; i <= n; i++) {
	    scanf("%lf %lf %lf", Yi + i, Xf + i, Yf + i);
	}

	double resp = 1e18;
	
	for (int i = 1; i <= n; i++) {
	    double Xn;
	    if (i % 2) {
		Xn = l;
		resp = min(resp, seg_dist(point(l, 0.0), point(l, h), point(Xf[i], Yf[i])));
	    } else {
		Xn = 0;
		resp = min(resp, seg_dist(point(0.0, 0.0), point(0.0, h), point(Xf[i], Yf[i])));
	    }

	    if (i == n) continue;
	    
	    resp = min(resp, seg_dist(point(Xn, Yi[i + 1]), point(Xf[i + 1], Yf[i + 1]), point(Xf[i], Yf[i])));
	}

	printf("%.2lf\n", resp);
    }
    return 0;
}

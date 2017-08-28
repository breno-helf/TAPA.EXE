#include<bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long double ld;

const int MAX = 112;
const ld eps = 1e-7;
const int lim = 300;


inline int cmp(ld x, ld y = 0, ld tol = eps) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct point {
    ld x, y;
    point(ld X = 0, ld Y = 0): x(X), y(Y) {}

    point operator +(point q) { return point(x + q.x, y + q.y); }
    point operator -(point q) { return point(x - q.x, y - q.y); }
    point operator *(ld t) { return point(x * t, y * t); }
    point operator /(ld t) { return point(x / t, y / t); }
    ld operator *(point q) { return (x * q.x + y * q.y); }
    ld operator %(point q) { return (x * q.y - y * q.x); }
    ld mod() { return sqrt(x * x + y * y); }

    int cmp(point q) const {
	if (int t = ::cmp(x, q.x)) return t;
	return ::cmp(y, q.y);
    }

    bool operator ==(point q) const { return cmp(q) == 0; }
    bool operator !=(point q) const { return cmp(q) != 0; }
    bool operator < (point q) const { return cmp(q) < 0; }        
};

ld a;
ld AREA;
int n;

vector<point> v;

ld poly_area(vector<point>& T) {
    ld s = 0; int m = T.size();

    for (int i = 0; i < m; i++) {
	s += T[i] % T[(i + 1) % m];
    }
    s = abs(s);
    return s / 2.0;
}

bool test(ld x) {

    ld tot = 0;
    
    for (int i = 0; i < n; i++) {
	vector<point> p;
	point A = v[i];
	point B = v[(i - 1 + n) % n];
	point C = v[(i + 1) % n];

	p.pb((B - A) / x + A);
	p.pb((C - A) / x + A);
	p.pb(A);

	double add = poly_area(p);
	

	// B = (B - A) + A;
	// C = (C - A) + A;
	
	tot += add;
	
	//printf("Orelha do %d tem area %.6lf\n", i, add); 
    }

    //tot /= x*x;
    
    ld prop = (AREA - tot);

    //printf("Proporçao eh %.6lf\n", prop);
    
    return cmp(prop, a * AREA) >= 0;
}

double bb() {
    ld ini = 2.0, fim = 1000.0;
    
    for (int k = 0; k < lim; k++) {
	ld meio = (ini + fim) / 2.0;
	if (test(meio)) fim = meio;
	else ini = meio;	
    }
    return fim;
}

double solve() {
    double L = AREA * (1.0 - a);
    double R = 0;

    for (int i = 0; i < n; i++) {
	vector<point> p;
	point A = v[i];
	point B = v[(i - 1 + n) % n];
	point C = v[(i + 1) % n];
	
	R += ((B - A) % (C - A)) / 2.0;
    }

    return sqrt(abs(R / L));
}

int main() {
    cin >> a >> n;
    
    for (int i = 0; i < n; i++) {
	ld x, y;
	cin >> x >> y;
	// x *= 5e6;
	// y *= 5e6;
	v.pb(point(x, y));
    }

    AREA = poly_area(v);
    
    //test(4.0);
    
    
    // cout << "--> ";
    // cout << fixed << setprecision(6) << bb() - 1000.0 << '\n';
    
    cout << fixed << setprecision(6) << solve() << '\n';
}

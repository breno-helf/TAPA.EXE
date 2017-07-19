#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const int MAX = 77;
const ld eps = 1e-9;

inline int cmp(ld x, ld y = 0, ld tol = eps) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct point {
    ld x, y, z;

    point(ld x = 0, ld y = 0, ld z = 0): x(x), y(y), z(z) {}
    point operator +(point q) { return point(x + q.x, y + q.y, z + q.z); }
    point operator -(point q) { return point(x - q.x, y - q.y, z - q.z); }
    point operator ^(point q) {
	return point(y * q.z - z * q.y, z * q.x - x * q.z, x * q.y - y * q.x);	
    }
    
    ld mod() { return sqrt(x * x + y * y + z * z); }
    
    ld operator *(point q) {
	return (x * q.x + y * q.y + z * q.z);
    }
    
    int cmp (point q) const {
	if (int t = ::cmp(x, q.x)) return t;
	if (int t = ::cmp(y, q.y)) return t;
	return ::cmp(z, q.z);
    }    
};

ld produto_misto(point p, point q, point r) {
    return (p ^ q) * r;
}

bool ishullface(vector<point> &T, int a, int b, int c) {
    int n = (int)T.size(), pos = 0, neg = 0;
    
    for (int i = 0; i < n; i++) {
	ld pm = produto_misto(T[b] - T[a], T[c] - T[a], T[i] - T[a]);
	if (cmp(pm) < 0) neg++;
	if (cmp(pm) > 0) pos++;
    }

    return (neg * pos == 0);
}

int n;
vector<point> P;
double resp;

ld area (point a, point b, point c) {
    return (0.5 * ((b - a) ^ (c - a)).mod());
}


int main () {
    cin.sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
	ld a, b, c;
	cin >> a >> b >> c;
	P.push_back(point(a, b, c));
    }
    resp = 0;
    int num = 0;
    for (int i = 0; i < n; i++) {
	for (int j = i + 1; j < n; j++) {
	    for (int k = j + 1; k < n; k++) {
		if (ishullface(P, i, j, k))  {
		    resp += area(P[i], P[j], P[k]);
		    ++num;
		}
	    }
	}
    }

    cout << fixed << setprecision(12) << resp << '\n';
    //cout << num << '\n';
}

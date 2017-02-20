//In god we trust
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 12;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

const double EPS = 1e-9;
const double PI = acos(-1);
const double PREC = 1e-5;
double GAMMA = 5e2;
double MINI = 1e-4;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct point {
    double x, y;
    point(double a, double b): x(a), y(b) {}
    point(): x(0.0), y(0.0) {}
    point operator +(point q) { return point(x + q.x, y + q.y); }
    point operator -(point q) { return point(x - q.x, y - q.y); }
    point operator *(double t) { return point(x * t, y * t); }
    point operator /(double t) { return point(x / t, y / t); }
    //a*b = |a||b|cos(ang) //dot product
    double operator *(point q) {return x * q.x + y * q.y;}
    //a%b = |a||b|sin(ang) //modulo do cross
    double operator ^(point q) {return x * q.y - y * q.x;}
    double polar() { return ((y > -EPS) ? atan2(y,x) : 2*PI + atan2(y,x)); }
    double mod() { return sqrt(x * x + y * y); }
    double mod2() { return (x * x + y * y); }
    point rotate(double t) {
	return point(x*cos(t)-y*sin(t), x*sin(t)+y*cos(t));
    }
    int cmp(point q) const {
	if (int t = ::cmp(x, q.x)) return t;
	return ::cmp(y, q.y);
    }
    bool operator ==(point q) const { return cmp(q) == 0; }
    bool operator !=(point q) const { return cmp(q) != 0; }
    bool operator < (point q) const { return cmp(q) < 0; }
};

typedef vector<point> polygon;

inline int ccw (point a, point b, point c) {
    return cmp((a - c) ^ (b - c));
}

double seg_distance(point p, point q, point r) {
    point A = r - q, B = r - p, C = q - p;
    double a = A * A, b = B * B, c = C * C;
    if (cmp(b, a + c) >= 0) return sqrt(a);
    else if (cmp(a, b + c) >= 0) return sqrt(b);
    else return fabs(A ^ B) / sqrt(c);
}

inline double angle(point p, point q, point r) {
    point u = p - q, v = r - q;
    return atan2(u ^ v, u * v);
}

int n;
double r, X, Y, ans;
double newX, newY, sum;
polygon P;

double area (point a, point b, point c) {
    double aa = (c - a).mod(), bb = (c - b).mod(), cc = seg_distance(a, b, c);

    if (cmp(aa, r) <= 0 && cmp(bb, r) <= 0) return 0.5 * fabs((a - c) ^ (b - c));

    if (cmp(cc, r) >= 0) return 0.5 * fabs(r * r * angle(a, c, b));

    if (cmp(aa, bb) > 0) {swap(a, b); swap(aa, bb); }

    double A = (a - b).mod2(), B = 2 * ((a - b) * (b - c)), C = (b - c).mod2() - r * r;

    double t = ((cmp(B*B - 4*A*C) == 0) ? 0.0 : sqrt(B*B - 4*A*C));

    double x1 = 0.5 * (-B -t) / A, x2 = 0.5 * (-B +t) / A;

    point p1 = a * x1 + b * (1 - x1), p2 = a * x2 + b * (1 - x2);
    if (cmp(aa, r) < 0) return area(a, p1, c) + area(p1, b, c);
    return area(a, p2, c) + area(p2, p1, c) + area(p1, b, c);
}

double calc (point c) {
    //    debug("--> %lf %lf ~~~~~ ", c.x, c.y);
    double ret = 0;
    for (int i = 0; i < n; i++)
	ret += (area(P[i], P[(i + 1) % n], c) * ccw (P[i], P[(i + 1) % n], c));
    //debug("%lf\n", ret);
    return abs(ret);
}

double pol_area () {
    double ret = 0;
    for (int i = 0; i < n; i++)
	ret += (P[i] ^ P[(i + 1) % n]);
    return ret / 2;
}


point center () {
    double x=0., y=0., area = pol_area();

    for (int i = 0; i < n - 1; i++) {
	x += (P[i].x + P[(i + 1) % n].x) * (P[i] ^ P[(i + 1) % n]);
	y += (P[i].y + P[(i + 1) % n].y) * (P[i] ^ P[(i + 1) % n]);
    }
    return point(x/(6*area), y/(6*area));
}

void solve () {
    double MUL = 1;
    point cur, nxt, GRAD, PRE, PPRE;
    cur = cur + point(1, 1);
    nxt = (calc(P[0]) > calc(center())) ? P[0] : center();
    ans = 0;
    PRE = point(0, 0);
    int i = 0;
    int lim = max(7 - n, 1) * 100000;
    debug(">> %lf\n", GAMMA);
    
    while ((cur - nxt).mod() > PREC && i < lim) {
	cur = nxt;
	sum = calc(cur);

	debug("==> (%lf, %lf)\n", cur.x, cur.y);
	
	GRAD.x = ((calc(cur + point(MINI, 0)) - sum)) * GAMMA;
	GRAD.y = ((calc(cur + point(0, MINI)) - sum)) * GAMMA;
	ans = max(sum, ans);
	
	if (GRAD == PRE) {
	    MUL += .5;
	} else if (GRAD == PPRE) {
	    GAMMA = 1e2;
	    MUL = 1;
	} else MUL = 1;

	
	PPRE = PRE;
	PRE = GRAD;
	GRAD.x *= MUL; GRAD.y *= MUL;
	
	debug("--> (%lf, %lf) -- %lf \n", GRAD.x, GRAD.y, MUL);

	
	nxt = nxt + GRAD;
	i++;
    }
    debug(".. %d\n", i);
    
    ans = max(ans, calc(nxt));
}

int main () {
    cin.sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> r;
    for (int i = 0; i < n; i++) {
	double x, y;
	cin >> x >> y;
	P.pb(point(x, y));
    }
    solve ();
    //point c = center();

    //cout << c.x << ' ' << c.y << " ---> " << calc(c) << '\n'; 
    
    cout << fixed << setprecision(5) << ans << '\n';
    return 0;
}

// Geometry Header
const double EPS = 1e-9;
const double PI = acos(-1);

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
    double polar() { return ((y > - EPS) ? atan2(y,x) : 2 * PI + atan2(y, x)); }
    double mod() { return sqrt(x * x + y * y); }
    double mod2() { return (x * x + y * y); }
    point rotate(double t) {
	return point(x * cos(t) - y * sin(t), x * sin(t) + y * cos(t));
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

#include "bits/stdc++.h"
using namespace std;

#define debug(args...) //fprintf(stderr, args)

int t, n;

struct point {
	double x, y;
	int type;
};

bool operator < (point a, point b) {
	return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}

vector <point> p;

point a[2], b[2];

bool ok(point o, point a, point b) {
	return (a.x - o.x) * (b.y - o.y) - (a.y- o.y) * (b.x - o.x) < 0.0; 
}

double cross(point o, point a, point b) {
	return (a.x - o.x) * (b.y - o.y) - (a.y- o.y) * (b.x - o.x); 
}

bool ok() {
	a[0] = p[0];
	a[1] = p[1];
	b[0] = p[2];
	b[1] = p[3];
	
	if(ok(a[0], a[1], b[0]) != ok(a[0], a[1], b[1]) && ok(b[0], b[1], a[0]) != ok(b[0], b[1], a[1])) {
		vector <point> Hull;
		int sz = -1;
		int mrk[] = {0, 0, 0, 0};
		
		sort(p.begin(), p.end());
		
		for(auto i: p)
			debug("%d ", i.type);
		debug("\n");
		
		for(int i = 0; i < n; ++i) {
			while(sz >= 1 && cross(Hull[sz - 1], Hull[sz], p[i]) < 0) {
				Hull.pop_back();
				--sz;
			}
			
			Hull.push_back(p[i]);
			++sz;
		}	
		
		for(auto i: Hull) {
			debug("%d ", i.type);
			if(i.type < 4)
				mrk[i.type] = true;
		}
		debug("\n");
		
		Hull.clear();
		sz = -1;
		
		for(int i = n - 1; i >= 0; --i) {
			while(sz >= 1 && cross(Hull[sz - 1], Hull[sz], p[i]) < 0) {
				Hull.pop_back();
				--sz;
			}
			
			Hull.push_back(p[i]);
			++sz;
		}
		
		for(auto i: Hull) {
			debug("%d ", i.type);
			if(i.type < 4)
				mrk[i.type] = true;
		}
		debug("\n");
		
		int cont = 0;
		for(int i = 0; i < 4; ++i)
			cont += mrk[i];
		
		return cont != 4;
	} 
	
	return true;
}

int main() {
	scanf("%d", &t);
	
	while(t--) {
		scanf("%d", &n);
		
		p.clear();
		for(int i = 0; i < n; ++i) {
			double x, y;
			scanf("%lf %lf", &x, &y);
			p.push_back( {x, y, i} );
		}
		
		if(ok())
			printf("POSSIBLE\n");
		else
			printf("IMPOSSIBLE\n");	
	}	
	
	return 0;
}
